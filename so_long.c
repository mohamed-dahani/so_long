/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:08:34 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/01 20:56:40 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!check_file_name(av[1]))
		{
			perror("invalid map !");
			exit(1);
		}
	}
	perror("please enter a map !");
	exit(1);
}