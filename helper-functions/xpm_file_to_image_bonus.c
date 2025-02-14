/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_file_to_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:36:33 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/10 15:43:47 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"\

int	xpm_file_to_image_bonus(t_map *map)
{
	int (w), (h);
	map->floor = mlx_xpm_file_to_image(map->mlx, "textures/floor.xpm", &w, &h);
	map->wall = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &w, &h);
	map->player = mlx_xpm_file_to_image(map->mlx, "textures/player.xpm", &w,
			&h);
	map->coin[0] = mlx_xpm_file_to_image(map->mlx, "textures/coin.xpm", &w, &h);
	map->coin[1] = mlx_xpm_file_to_image(map->mlx, "textures/coin2.xpm", &w,
			&h);
	map->coin[2] = mlx_xpm_file_to_image(map->mlx, "textures/coin3.xpm", &w,
			&h);
	map->coin[3] = mlx_xpm_file_to_image(map->mlx, "textures/coin4.xpm", &w,
			&h);
	map->coin[4] = mlx_xpm_file_to_image(map->mlx, "textures/coin5.xpm", &w,
			&h);
	map->coin[5] = mlx_xpm_file_to_image(map->mlx, "textures/coin6.xpm", &w,
			&h);
	map->enemy = mlx_xpm_file_to_image(map->mlx, "textures/enemy.xpm", &w, &h);
	map->exit = mlx_xpm_file_to_image(map->mlx, "textures/exit.xpm", &w, &h);
	if (!map->floor || !map->wall || !map->player || !map->coin[0]
		|| !map->coin[1] || !map->coin[2] || !map->coin[3] || !map->coin[4]
		|| !map->coin[5] || !map->enemy || !map->exit)
		return (0);
	return (1);
}
