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

void	cleanup(t_map_data *map)
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
