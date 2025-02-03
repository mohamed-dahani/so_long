/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:13:28 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/03 17:16:59 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct s_map
{
	char	**map;
	int		rows;
	int		columns;
}			t_map;

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

int		check_file_name(char *av);
int		check_map(char *filename, t_map *map);
void	free_array(char **ptr, int i);

#endif
