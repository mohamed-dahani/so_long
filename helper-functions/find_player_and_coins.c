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

#include "../includes/so_long.h"

void	find_player_and_coins(t_map_data *map)
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
}
