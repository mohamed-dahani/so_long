/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:08:03 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/04 15:42:16 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_file_name(char *av)
{
	size_t	len;

	len = ft_strlen(av);
	if (len > 4 && av[len - 4] == '.' && av[len - 3] == 'b'
		&& av[len - 2] == 'e' && av[len - 1] == 'r')
		return (1);
	return (0);
}
