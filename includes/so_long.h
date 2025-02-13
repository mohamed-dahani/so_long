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

typedef struct s_enemy {
    int x;
    int y;
    int dir;
} t_enemy;

typedef struct s_map
{
	int		_0;
	int		_1;
	int		p;
	int		c;
	int		n;
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
	void	*coin[6];
	void	*enemy;
	void	*exit;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		coin_frame;
	t_enemy *enemies;
    int 	enemy_count;
	int		moves;
}			t_map;

size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);
int			ft_printf(const char *string, ...);
char		*ft_itoa(int n);

void		custom_error(char *msg);
int			check_file_name(char *av);
int			check_map(char *filename, t_map *map);
int			flood_fill(t_map *map);
int			check_edges_map(t_map *map);
void		free_array(char **ptr, int i);
int			run_window(t_map *map);
int			xpm_file_to_image(t_map *map);
void		find_player_and_coins_and_enemy(t_map *map);
void		draw_map(t_map *map);
void		move_player(t_map *map, int move_x, int move_y);
void		animate_coin(t_map *map);
void		animate_enemy(t_map *map);
void		cleanup(t_map *map);
void		print_moves_in_window(t_map *map);

#endif
