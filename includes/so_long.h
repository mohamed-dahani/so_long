/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:13:28 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/08 18:21:40 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_map
{
	char	**copy_map;
	char	**map;
	int		rows;
	int		columns;
	void    *mlx;
    void    *window;
    void    *player;
    void    *floor;
    void    *wall;
    void    *coin;
    void    *exit;
    int     player_x;
    int     player_y;
    int     collectibles;
    void    *coins[6];
    int     coin_frame;
}			t_map;

size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);
int	        ft_printf(const char *string, ...);

void		custom_error(char *msg);
int			check_file_name(char *av);
int			check_map(char *filename, t_map *map);
int			flood_fill(t_map *map);
int			check_edges_map(t_map *map);
void		free_array(char **ptr, int i);
int			run_window(t_map *map);

#endif
