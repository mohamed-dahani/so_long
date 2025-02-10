/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_and_coins_and_enemy.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:13:33 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/10 16:17:04 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	find_enemy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->enemy_x = -1;
	map->enemy_y = -1;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N')
			{
				map->enemy_x = j;
				map->enemy_y = i;
			}
			j++;
		}
		i++;
	}
}

void	find_player_and_coins_and_enemy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->collectibles = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
			}
			else if (map->map[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	find_enemy(map);
}
