/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_edges_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:27:02 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/04 15:44:15 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_edges_map(t_map *map)
{
	int (i), (j);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (i == 0 && map->copy_map[i][j] != '1')
				return (0);
			if (i == (map->rows - 1) && map->copy_map[map->rows - 1][j] != '1')
				return (0);
			if (j == 0 && map->copy_map[i][j] != '1')
				return (0);
			if (j == (map->columns - 1) && map->copy_map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
