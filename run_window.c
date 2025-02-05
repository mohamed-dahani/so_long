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
	map->window = mlx_new_window(map->mlx, map->columns * 128, map->rows * 128, "so_long");
	if (!map->window)	
		return (0);

	int w,h;
	void *img_ptr= mlx_xpm_file_to_image(map->mlx,"floor.xpm",&w,&h);
	
	int i = 1;
	while (i <= 1664)
	{
		mlx_put_image_to_window(map->mlx, map->window,img_ptr,i,1);
		i+= 64;
	}
	mlx_loop(map->mlx);
	return (1);
}
