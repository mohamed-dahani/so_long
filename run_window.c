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

int	onkey_press(int key_code,t_map *map)
{
	if (key_code == XK_Escape)
	{
		(void) map;
		exit(0);
	}
	return(1);
}

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
	void *wall = mlx_xpm_file_to_image(map->mlx,"wall.xpm",&w,&h);
	void *player = mlx_xpm_file_to_image(map->mlx,"player.xpm",&w,&h);
	void *coin = mlx_xpm_file_to_image(map->mlx,"coin.xpm",&w,&h);
	void *exit = mlx_xpm_file_to_image(map->mlx,"exit.xpm",&w,&h);
	if (!floor || !player || !coin || !exit)
		return (0);
	int i = 0;
	while (map->map[i])
	{
		int j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->window,floor, j * 64, i * 64);
			else if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->window,wall, j * 64, i * 64);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->window,player, j * 64, i * 64);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->window,coin, j * 64, i * 64);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->window,exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_key_hook(map->window, &onkey_press, map);
	mlx_loop(map->mlx);
	return (1);
}
