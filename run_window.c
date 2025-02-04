/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:49:18 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/04 21:50:12 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	run_window(t_map *map, t_window *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		return (0);
	window->window = mlx_new_window(window->mlx, map->columns * 128, map->rows * 128, "so_long");
	if (!window->window)	
		return (0);
	mlx_loop(window->mlx);
	return (1);
}
