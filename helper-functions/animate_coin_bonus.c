/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_coin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:20:43 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/10 16:21:08 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	animate_coin(t_map *map)
{
	static int	frame_counter;
	const int	delay = 20;

	frame_counter++;
	if (frame_counter >= delay)
	{
		frame_counter = 0;
		map->coin_frame = (map->coin_frame + 1) % 6;
	}
	draw_map(map);
}
