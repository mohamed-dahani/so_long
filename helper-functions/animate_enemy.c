/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:32 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/11 18:23:17 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	game_over(t_map *map, int new_y)
{
	if (map->map[new_y][map->enemy_x] == 'P'
		|| map->map[map->enemy_y][map->enemy_x] == 'P')
	{
		ft_printf("Game Over!\n");
		cleanup(map);
		exit(0);
	}
	return (1);
}

void	animate_enemy(t_map *map)
{
	static int	frame = 0;
	const int	speed = 30;
	int			new_y;

	frame++;
	if (frame >= speed)
	{
		frame = 0;
		new_y = map->enemy_y + map->enemy_dir;
		game_over(map, new_y);
		if (new_y < 0 || new_y >= map->rows
			|| map->map[new_y][map->enemy_x] == '1')
		{
			map->enemy_dir *= -1;
			new_y = map->enemy_y + map->enemy_dir;
		}
		if (new_y >= 0 && new_y < map->rows
			&& map->map[new_y][map->enemy_x] != '1')
		{
			map->map[map->enemy_y][map->enemy_x] = '0';
			map->enemy_y = new_y;
			map->map[map->enemy_y][map->enemy_x] = 'N';
			draw_map(map);
		}
	}
}
