/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:38:09 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/09 20:52:23 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "helper-functions/get_next_line/get_next_line.h"

void	cleanup(t_map *map)
{
	if (map->enemy)
		mlx_destroy_image(map->mlx, map->enemy);
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
	if (map->coin[0])
		mlx_destroy_image(map->mlx, map->coin[0]);
    if (map->coin[1])
		mlx_destroy_image(map->mlx, map->coin[1]);
    if (map->coin[2])
		mlx_destroy_image(map->mlx, map->coin[2]);
    if (map->coin[3])
		mlx_destroy_image(map->mlx, map->coin[3]);
    if (map->coin[4])
		mlx_destroy_image(map->mlx, map->coin[4]);
    if (map->coin[5])
		mlx_destroy_image(map->mlx, map->coin[5]);
	if (map->player)
		mlx_destroy_image(map->mlx, map->player);
	if (map->wall)
		mlx_destroy_image(map->mlx, map->wall);
	if (map->floor)
		mlx_destroy_image(map->mlx, map->floor);
	if (map->window)
		mlx_destroy_window(map->mlx, map->window);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
    // if (map->moves_int_to_str)
    //     free(map->moves_int_to_str);
    free_array(map->map, map->rows);
}

void find_player_and_coins_and_enemy(t_map *map)
{
    int i = 0;
    map->collectibles = 0;
    map->enemy_x = -1;
    map->enemy_y = -1;
    while (map->map[i])
    {
        int j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == 'P')
            {
                map->player_x = j;
                map->player_y = i;
            }
            else if (map->map[i][j] == 'C')
                map->collectibles++;
			else if (map->map[i][j] == 'N')
			{
				map->enemy_x = j;
				map->enemy_y = i;
			}
            j++;
        }
        i++;
    }
}

void	draw_map(t_map *map)
{
    mlx_clear_window(map->mlx, map->window);
    int i = 0;
    while (map->map[i])
    {
        int j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == '0')
                mlx_put_image_to_window(map->mlx, map->window, map->floor, j * 64, i * 64);
            else if (map->map[i][j] == '1')
                mlx_put_image_to_window(map->mlx, map->window, map->wall, j * 64, i * 64);
            else if (map->map[i][j] == 'P')
                mlx_put_image_to_window(map->mlx, map->window, map->player, j * 64, i * 64);
            else if (map->map[i][j] == 'C')
                mlx_put_image_to_window(map->mlx, map->window, map->coin[map->coin_frame], j * 64, i * 64);
            else if (map->map[i][j] == 'N')
                mlx_put_image_to_window(map->mlx, map->window, map->enemy, j * 64, i * 64);
            else if (map->map[i][j] == 'E')
                mlx_put_image_to_window(map->mlx, map->window, map->exit, j * 64, i * 64);
            j++;
        }
        i++;
    }
    // mlx_string_put(map->mlx, map->window, 20, 40, 0xFFFFFF, map->moves_int_to_str);
}

void	move_player(t_map *map, int move_x, int move_y)
{
    int new_x = map->player_x + move_x;
    int new_y = map->player_y + move_y;
    static int moves;
    if (map->map[new_y][new_x] == '1')
        return;
    if (map->map[new_y][new_x] == 'C')
    {
        map->collectibles--;
        map->map[new_y][new_x] = '0';
    }
    if (map->map[new_y][new_x] == 'E')
    {
        if (map->collectibles == 0)
        {
            ft_printf("You win!\n");
            cleanup(map);
            exit(0);
        }
        else
            return; 
    }
    map->map[map->player_y][map->player_x] = '0'; 
    map->player_x = new_x;
    map->player_y = new_y;
    map->map[new_y][new_x] = 'P'; 
    ft_printf("moves: %d\n", ++moves);
    
    // // Free existing moves string
    // if (map->moves_int_to_str)
    //     free(map->moves_int_to_str);
    
    // // Generate new moves string
    // map->moves_int_to_str = ft_itoa(moves);
    draw_map(map);
}

int	on_keypress(int key_code, t_map *map)
{
    if (key_code == XK_Escape)
    {
        cleanup(map);
        exit(0);
    }
    else if (key_code == XK_w || key_code == XK_Up)
        move_player(map, 0, -1);
    else if (key_code == XK_s || key_code == XK_Down)
        move_player(map, 0, 1);
    else if (key_code == XK_a || key_code == XK_Left)
        move_player(map, -1, 0);
    else if (key_code == XK_d || key_code == XK_Right)
        move_player(map, 1, 0);
    return (1);
}

int close_window(t_map *map)
{
    cleanup(map);
    exit(0);
}

void animate_coin(t_map *map)
{
    static int  frame_counter;
    const int   delay = 10;

    frame_counter++;
    if (frame_counter >= delay)
    {
        frame_counter = 0;
        map->coin_frame = (map->coin_frame + 1) % 6;
    }
    draw_map(map);    
}

void animate_enemy(t_map *map)
{
    static int frame = 0;
    const int speed = 30;

    frame++;
    if (frame >= speed)
    {
        frame = 0;
        int new_y = map->enemy_y + map->enemy_dir;

        if (map->map[new_y][map->enemy_x] == 'P')
        {
            ft_printf("Game Over!\n");
            cleanup(map);
            exit(0);
        }
        if (map->map[map->enemy_y][map->enemy_x] == 'P')
        {
            ft_printf("Game Over!\n");
            cleanup(map);
            exit(0);
        }
        if (new_y < 0 || new_y >= map->rows || map->map[new_y][map->enemy_x] == '1')
        {
            map->enemy_dir *= -1;
            new_y = map->enemy_y + map->enemy_dir;
        }
        if (new_y >= 0 && new_y < map->rows && map->map[new_y][map->enemy_x] != '1')
        {
            map->map[map->enemy_y][map->enemy_x] = '0';
            map->enemy_y = new_y;
            map->map[map->enemy_y][map->enemy_x] = 'N';
            draw_map(map);
        }
    }
}


int animation(t_map *map)
{
    animate_coin(map);
    animate_enemy(map);
    return (1);    
}


int	run_window(t_map *map)
{
    map->mlx = mlx_init();
    if (!map->mlx)
        return (0);
    map->window = mlx_new_window(map->mlx, map->columns * 64, map->rows * 64, "so_long");
    if (!map->window)
        return (0);

    int w, h;
    map->floor = mlx_xpm_file_to_image(map->mlx, "textures/floor.xpm", &w, &h);
    map->wall = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &w, &h);
    map->player = mlx_xpm_file_to_image(map->mlx, "textures/player.xpm", &w, &h);
    map->coin[0] = mlx_xpm_file_to_image(map->mlx, "textures/coin.xpm", &w, &h);
    map->coin[1] = mlx_xpm_file_to_image(map->mlx, "textures/coin2.xpm", &w, &h);
    map->coin[2] = mlx_xpm_file_to_image(map->mlx, "textures/coin3.xpm", &w, &h);
    map->coin[3] = mlx_xpm_file_to_image(map->mlx, "textures/coin4.xpm", &w, &h);
    map->coin[4] = mlx_xpm_file_to_image(map->mlx, "textures/coin5.xpm", &w, &h);
    map->coin[5] = mlx_xpm_file_to_image(map->mlx, "textures/coin6.xpm", &w, &h);
    map->enemy = mlx_xpm_file_to_image(map->mlx, "textures/enemy.xpm", &w, &h);
    map->exit = mlx_xpm_file_to_image(map->mlx, "textures/exit.xpm", &w, &h);
    if (!map->floor || !map->wall || !map->player || !map->coin[0] || !map->coin[1] || !map->coin[2] || !map->coin[3] || !map->coin[4] || !map->coin[5] || !map->enemy || !map->exit)
    {
        cleanup(map);
        return (0);
    }
    map->coin_frame = 0;
	map->enemy_dir = 1;
    find_player_and_coins_and_enemy(map);
    draw_map(map);
    mlx_hook(map->window, KeyPress, KeyPressMask, &on_keypress, map);
    mlx_hook(map->window, 17, 0, &close_window, map);
    mlx_loop_hook(map->mlx, &animation, map);
    mlx_loop(map->mlx);
    return (1);
}
