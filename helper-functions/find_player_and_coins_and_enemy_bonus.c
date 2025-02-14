/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_and_coins_and_enemy.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:13:33 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/13 21:22:59 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	store_position_of_enemy(t_map *map)
{
	int	i;
	int	j;
	int	idx;

	map->enemies = malloc(map->enemy_count * sizeof(t_enemy));
	if (!map->enemies)
		exit(1);
	idx = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N')
			{
				map->enemies[idx].x = j;
				map->enemies[idx].y = i;
				map->enemies[idx].dir = 1;
				idx++;
			}
			j++;
		}
		i++;
	}
}

static void	find_enemy(t_map *map)
{
	int	i;
	int	j;

	map->enemy_count = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N')
				map->enemy_count++;
			j++;
		}
		i++;
	}
	store_position_of_enemy(map);
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
