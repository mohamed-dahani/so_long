 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:49:18 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/04 23:01:06 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int on_keypress(int key_code, t_map *map)
{
    if (key_code == XK_Escape)
        exit(0);
    else if (key_code == XK_w || key_code == XK_Up)
        move_player(map, 0, -1);
    else if (key_code == XK_s || key_code == XK_Down)
        move_player(map, 0, 1);
    else if (key_code == XK_a || key_code == XK_Left)
        move_player(map, -1, 0);
    else if (key_code == XK_d || key_code == XK_Right)
        move_player(map, 1, 0);
    return (0);
}

void move_player(t_map *map, int dx, int dy)
{
    int new_x = map->player_x + dx;
    int new_y = map->player_y + dy;

    // Wall collision check
    if (map->map[new_y][new_x] == '1')
        return;

    // Collectible handling
    if (map->map[new_y][new_x] == 'C')
    {
        map->collectibles--;
        map->map[new_y][new_x] = '0'; // Remove collectible
    }

    // Exit handling
    if (map->map[new_y][new_x] == 'E')
    {
        if (map->collectibles == 0)
        {
            printf("You win!\n");
            exit(0);
        }
        else
            return; // Exit locked
    }

    // Update player position
    map->map[map->player_y][map->player_x] = '0'; // Clear old position
    map->player_x = new_x;
    map->player_y = new_y;
    map->map[new_y][new_x] = 'P'; // Set new position

    // Redraw the updated map
    redraw_map(map);
}

void redraw_map(t_map *map)
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

int run_window(t_map *map)
{
    map->mlx = mlx_init();
    if (!map->mlx)
        return (0);
    map->window = mlx_new_window(map->mlx, map->columns * 64, map->rows * 64, "so_long");
    if (!map->window)
        return (0);

    int w, h;
    map->floor = mlx_xpm_file_to_image(map->mlx, "floor.xpm", &w, &h);
    map->wall = mlx_xpm_file_to_image(map->mlx, "wall.xpm", &w, &h);
    map->player = mlx_xpm_file_to_image(map->mlx, "player.xpm", &w, &h);
    map->coin = mlx_xpm_file_to_image(map->mlx, "coin.xpm", &w, &h);
    map->exit = mlx_xpm_file_to_image(map->mlx, "exit.xpm", &w, &h);
    if (!map->floor || !map->player || !map->coin || !map->exit)
        return (0);

    // Find player position and count collectibles
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

    // Draw the initial map
    redraw_map(map);

    // Set up keypress handler
    mlx_hook(map->window, KeyPress, KeyPressMask, &on_keypress, map);

    // Start the main loop
    mlx_loop(map->mlx);
    return (1);
}
