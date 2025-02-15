/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:32 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/15 17:36:16 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	game_over(t_enemy *enemy, t_map *map, int new_y)
{
	if ((enemy->y == map->player_y && enemy->x == map->player_x)
		|| (new_y == map->player_y && enemy->x == map->player_x))
	{
		ft_printf("Game Over!\n");
		cleanup_bonus(map);
		exit(0);
	}
	return (1);
}

static void	check_enemy_moves(t_map *map, int new_y, t_enemy *enemy)
{
	if (new_y < 0 || new_y >= map->rows || map->map[new_y][enemy->x] == '1'
		|| map->map[new_y][enemy->x] == 'N' || map->map[new_y][enemy->x] == 'C'
		|| map->map[new_y][enemy->x] == 'E')
	{
		enemy->dir *= -1;
		new_y = enemy->y + enemy->dir;
	}
	if (new_y >= 0 && new_y < map->rows && map->map[new_y][enemy->x] != '1'
		&& map->map[new_y][enemy->x] != 'N' && map->map[new_y][enemy->x] != 'C'
		&& map->map[new_y][enemy->x] != 'E')
	{
		map->map[enemy->y][enemy->x] = '0';
		enemy->y = new_y;
		map->map[enemy->y][enemy->x] = 'N';
	}
}

void	animate_enemy(t_map *map)
{
	static int	frame = 0;
	const int	speed = 60;
	int			i;
	t_enemy		*enemy;
	int			new_y;

	frame++;
	if (frame >= speed)
	{
		frame = 0;
		i = 0;
		while (i < map->enemy_count)
		{
			enemy = &map->enemies[i];
			new_y = enemy->y + enemy->dir;
			game_over(enemy, map, new_y);
			check_enemy_moves(map, new_y, enemy);
			i++;
		}
		draw_map_bonus(map);
	}
}
