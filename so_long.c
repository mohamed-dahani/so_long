/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:08:34 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/02 20:57:12 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int ac, char **av)
{
	t_map map;

	if (ac != 2 || !check_file_name(av[1]))
		return (write(2, "Error\nNo such file or directory !\n", 34), 1);
	if (!check_map(av[1], &map))
		return(write(2, "Error\ninvalid map !\n", 20), 1);
}
