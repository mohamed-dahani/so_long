/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:38:09 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/07 20:33:05 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	cleanup(t_map *map)
{
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
	if (map->coin)
		mlx_destroy_image(map->mlx, map->coin);
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
    free_array(map->map, map->rows);
}

void find_player_and_coins(t_map *map)
{
    int i = 0;
    map->collectibles = 0;
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
                mlx_put_image_to_window(map->mlx, map->window, map->coin, j * 64, i * 64);
            else if (map->map[i][j] == 'E')
                mlx_put_image_to_window(map->mlx, map->window, map->exit, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

void	move_player(t_map *map, int move_x, int move_y)
{
    int new_x = map->player_x + move_x;
    int new_y = map->player_y + move_y;
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
            printf("You win!\n");
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
    draw_map(map);
}

int	on_keypress(int key_code, t_map *map)
{
    static int moves;

    if (key_code == XK_Escape)
    {
        cleanup(map);
        exit(0);
    }
    else if (key_code == XK_w || key_code == XK_Up)
    {
        move_player(map, 0, -1);
        printf("moves: %d\n", ++moves);
    }
    else if (key_code == XK_s || key_code == XK_Down)
    {
        move_player(map, 0, 1);
        printf("moves: %d\n", ++moves);
    }
    else if (key_code == XK_a || key_code == XK_Left)
    {
        move_player(map, -1, 0);
        printf("moves: %d\n", ++moves);
    }
    else if (key_code == XK_d || key_code == XK_Right)
    {
        move_player(map, 1, 0);
        printf("moves: %d\n", ++moves);
    }
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
    map->coin = mlx_xpm_file_to_image(map->mlx, "textures/coin.xpm", &w, &h);
    map->exit = mlx_xpm_file_to_image(map->mlx, "textures/exit.xpm", &w, &h);
    if (!map->floor || !map->wall || !map->player || !map->coin || !map->exit)
    {
        cleanup(map);
        return (0);
    }
    find_player_and_coins(map);
    draw_map(map);
    mlx_hook(map->window, KeyPress, KeyPressMask, &on_keypress, map);
    mlx_loop(map->mlx);
    return (1);
}
