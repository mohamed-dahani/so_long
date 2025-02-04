/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:08:34 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/04 17:02:52 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_window	window;

	if (ac != 2 || !check_file_name(av[1]))
		return (custom_error("Error\nNo such file or directory !\n"), 1);
	if (!check_map(av[1], &map))
		return (custom_error("Error\nInvalid map !\n"), 1);
	if (!run_window(&map, &window))
		return (custom_error("Error\nWindow is not running !\n"), 1);
}
