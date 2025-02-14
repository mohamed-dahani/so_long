/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:13:28 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/13 21:06:38 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map_data
{
	int		_0;
	int		_1;
	int		p;
	int		c;
	int		e;
	char	**copy_map;
	char	**map;
	int		rows;
	int		columns;
	void	*mlx;
	void	*window;
	void	*player;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
}			t_map_data;

size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);
int			ft_printf(const char *string, ...);
char		*ft_itoa(int n);

void		custom_error(char *msg);
int			check_file_name(char *av);
int			check_map(char *filename, t_map_data *map);
int			flood_fill(t_map_data *map);
int			check_edges_map(t_map_data *map);
void		free_array(char **ptr, int i);
int			run_window(t_map_data *map);
int			xpm_file_to_image(t_map_data *map);
void		find_player_and_coins(t_map_data *map);
int			draw_map(t_map_data *map);
void		move_player(t_map_data *map, int move_x, int move_y);
void		cleanup(t_map_data *map);

#endif
