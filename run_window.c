/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:38:09 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/13 21:17:49 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	on_keypress(int key_code, t_map *map)
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

static int	close_window(t_map *map)
{
	cleanup(map);
	exit(0);
}

static int	animation(t_map *map)
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
	map->window = mlx_new_window(map->mlx, map->columns * 64, map->rows * 64,
			"so_long");
	if (!map->window)
		return (0);
	if (!xpm_file_to_image(map))
	{
		cleanup(map);
		return (0);
	}
	map->coin_frame = 0;
	map->moves = 0;
	find_player_and_coins_and_enemy(map);
	draw_map(map);
	mlx_hook(map->window, KeyPress, KeyPressMask, &on_keypress, map);
	mlx_hook(map->window, 17, 0, &close_window, map);
	mlx_loop_hook(map->mlx, &animation, map);
	mlx_loop(map->mlx);
	return (1);
}
