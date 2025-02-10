/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:41:02 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/10 16:47:23 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	you_win(t_map *map)
{
	ft_printf("You win!\n");
	cleanup(map);
	exit(0);
}

void	move_player(t_map *map, int move_x, int move_y)
{
	int	new_x;
	int	new_y;

	new_x = map->player_x + move_x;
	new_y = map->player_y + move_y;
	if (map->map[new_y][new_x] == '1')
		return ;
	if (map->map[new_y][new_x] == 'C')
	{
		map->collectibles--;
		map->map[new_y][new_x] = '0';
	}
	if (map->map[new_y][new_x] == 'E')
	{
		if (map->collectibles == 0)
			you_win(map);
		else
			return ;
	}
	map->map[map->player_y][map->player_x] = '0';
	map->player_x = new_x;
	map->player_y = new_y;
	map->map[new_y][new_x] = 'P';
	map->moves++;
	ft_printf("moves: %d\n", map->moves);
}
