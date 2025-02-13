/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:29:53 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/13 21:09:24 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	destroy_image_coin(t_map *map)
{
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
}

void	cleanup(t_map *map)
{
	if (map->enemy)
		mlx_destroy_image(map->mlx, map->enemy);
	if (map->enemies)
    	free(map->enemies);
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
	destroy_image_coin(map);
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
