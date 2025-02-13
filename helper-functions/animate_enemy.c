/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:32 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/13 21:08:05 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void animate_enemy(t_map *map) {
    static int frame = 0;
    const int speed = 30;

    frame++;
    if (frame >= speed) {
        frame = 0;
        for (int i = 0; i < map->enemy_count; i++) {
            t_enemy *enemy = &map->enemies[i];
            int new_y = enemy->y + enemy->dir;

            // Check collision with player
            if ((enemy->y == map->player_y && enemy->x == map->player_x) ||
                (new_y == map->player_y && enemy->x == map->player_x)) {
                ft_printf("Game Over!\n");
                cleanup(map);
                exit(0);
            }

            // Handle movement
            if (new_y < 0 || new_y >= map->rows || 
                map->map[new_y][enemy->x] == '1') {
                enemy->dir *= -1;
                new_y = enemy->y + enemy->dir;
            }

            if (new_y >= 0 && new_y < map->rows && 
                map->map[new_y][enemy->x] != '1') {
                // Update map and enemy position
                map->map[enemy->y][enemy->x] = '0';
                enemy->y = new_y;
                map->map[enemy->y][enemy->x] = 'N';
            }
        }
        draw_map(map);
    }
}
