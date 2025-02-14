/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves_in_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:52:00 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/10 15:57:59 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "get_next_line/get_next_line.h"

void	print_moves_in_window(t_map *map)
{
	char	*moves_num;
	char	*moves_str;

	moves_num = ft_itoa(map->moves);
	moves_str = ft_strjoin("Moves: ", moves_num);
	mlx_string_put(map->mlx, map->window, 20, 40, 0xFFFFFF, moves_str);
	free(moves_str);
	free(moves_num);
}
