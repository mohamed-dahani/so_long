/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:05:17 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/03 19:54:42 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "helper-functions/get_next_line/get_next_line.h"


// int check_rectangle(char *str)
// {
//     //check nafes size 
// }
static int check_valid_character(int fd, t_map *map)
{
	char	*line;
	int		(i), (P), (C), (E);

	P = 0;
	C = 0;
	E = 0;
	map->rows = 0;
	while ((line = get_next_line(fd)))
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == 'P')
				P++;
			if (line[i] == 'C')
				C++;
			if (line[i] == 'E')
				E++;
			i++;
		}
		map->rows++;
		free(line);
	}
	close(fd);
	return (P == 1 && C != 0 && E == 1);
}

char **read_map(int fd, t_map *map, char  *filename)
{
	char 	**lines;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	lines = malloc(sizeof(char *) * (map->rows + 1));
	if (!lines)
		return NULL;
	while (i  < map->rows)
	{
		lines[i] = get_next_line(fd);
		i++;
	}
	lines[i] = NULL;
	return (lines);
}

int check_size_map(t_map *map)
{
	int 	i;
	size_t	line_length;

	line_length = ft_strlen(map->map[0]);
	i = 0;
	while (map->map[i])
	{
		if (line_length != ft_strlen(map->map[i]))
			return (0);
		i++;
	}
	map->columns = (int)line_length - 1;
	return (1);
}
int	check_all_chars(t_map *map)
{
	int i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != 'P' && map->map[i][j] != 'C' && map->map[i][j] != 'E'
				&& map->map[i][j] != '0' && map->map[i][j] != '1' && map->map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill_rec(t_map *map, int x, int y)
{
	
	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns)
		return ;
	if (map->map[x][y] != '0' && map->map[x][y] != 'C')
		return ;
	map->map[x][y] = 'V';
	flood_fill_rec(map, x + 1, y);
	flood_fill_rec(map, x - 1, y);
	flood_fill_rec(map, x, y + 1);
	flood_fill_rec(map, x, y - 1);
}

int	flood_fill(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns)
		{
			if (map->map[x][y] == 'P')
			{
				printf("x: %d\ny: %d\n", x, y);
				flood_fill_rec(map, x, y);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);	
}

void print_map(t_map *map)
{
	for(int i = 0; i < map->rows; i++)
		printf("%s", map->map[i]);
}
int	check_map(char *filename, t_map *map)
{
	int	fd;
	fd = open(filename, O_RDONLY);
	if (!check_valid_character(fd, map))
		return (0);
	map->map = read_map(fd, map, filename);
	if (!map->map)
		return (0);
	if (!check_size_map(map))
		return (free_array(map->map, map->rows), 0);
	if (!check_all_chars(map))
		return (free_array(map->map, map->rows), 0);
	if (!flood_fill(map))
		return (free_array(map->map, map->rows), 0);
	printf("rows: %d\ncolumns: %d\n", map->rows, map->columns);
	print_map(map);
	free_array(map->map, map->rows);
	return (1);
}
