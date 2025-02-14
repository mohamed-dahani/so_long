/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:03:28 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/10 19:39:00 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	change_char_to_image(t_map_data *map, int i)
{
	int	j;

	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == '0')
			mlx_put_image_to_window(map->mlx, map->window, map->floor, j * 64, i
				* 64);
		else if (map->map[i][j] == '1')
			mlx_put_image_to_window(map->mlx, map->window, map->wall, j * 64, i
				* 64);
		else if (map->map[i][j] == 'P')
			mlx_put_image_to_window(map->mlx, map->window, map->player, j * 64,
				i * 64);
		else if (map->map[i][j] == 'C')
			mlx_put_image_to_window(map->mlx, map->window, map->coin, j * 64, i * 64);
		else if (map->map[i][j] == 'E')
			mlx_put_image_to_window(map->mlx, map->window, map->exit, j * 64, i
				* 64);
		j++;
	}
}

int	draw_map(t_map_data *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		change_char_to_image(map, i);
		i++;
	}
	return (1);
}
