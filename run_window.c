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

int	run_window(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (0);
	map->window = mlx_new_window(map->mlx, map->columns * 64, map->rows * 64, "so_long");
	if (!map->window)	
		return (0);

	int w,h;
	void *floor = mlx_xpm_file_to_image(map->mlx,"floor.xpm",&w,&h);
	void *palyer = mlx_xpm_file_to_image(map->mlx,"player.xpm",&w,&h);
	void *coin = mlx_xpm_file_to_image(map->mlx,"coin.xpm",&w,&h);
	void *enemy = mlx_xpm_file_to_image(map->mlx,"enemy.xpm",&w,&h);
	if (!floor || !palyer || !coin || !enemy)
		return (0);
	int i = 0;
	while (map->map[i])
	{
		int j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->window,floor, j * 64, i * 64);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->window,palyer, j * 64, i * 64);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->window,coin, j * 64, i * 64);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->window,enemy, j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_loop(map->mlx);
	return (1);
}
