/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:13:28 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/04 15:49:13 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**copy_map;
	char	**map;
	int		rows;
	int		columns;
}			t_map;

size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);

void		custom_error(char *msg);
int			check_file_name(char *av);
int			check_map(char *filename, t_map *map);
int			flood_fill(t_map *map);
int			check_edges_map(t_map *map);
void		free_array(char **ptr, int i);

#endif
