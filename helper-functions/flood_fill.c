/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:24:09 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/08 20:54:24 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill_rec(t_map *map, int x, int y)
{
    if (x < 0 || x >= map->rows || y < 0 || y >= map->columns)
        return ;
    if (map->copy_map[x][y] != '0' && map->copy_map[x][y] != 'C'
        && map->copy_map[x][y] != 'P' && map->copy_map[x][y] != 'N'
        && map->copy_map[x][y] != 'E')
        return ;
    map->copy_map[x][y] = 'V';
    flood_fill_rec(map, x + 1, y);
    flood_fill_rec(map, x - 1, y);
    flood_fill_rec(map, x, y + 1);
    flood_fill_rec(map, x, y - 1);
}

static int	check_flood_fill(t_map *map)
{
    int	i;
    int	j;

    i = 0;
    while (map->copy_map[i])
    {
        j = 0;
        while (map->copy_map[i][j])
        {
            if (map->copy_map[i][j] == 'C' || map->copy_map[i][j] == 'E')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int	flood_fill(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns)
		{
			if (map->copy_map[x][y] == 'P')
			{
				flood_fill_rec(map, x, y);
				if (check_flood_fill(map))
					return (1);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (0);
}
