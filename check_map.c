/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:05:17 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/04 15:19:46 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "helper-functions/get_next_line/get_next_line.h"

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
	int		len;

	i = 0;
	fd = open(filename, O_RDONLY);
	lines = malloc(sizeof(char *) * (map->rows + 1));
	if (!lines)
		return NULL;
	while (i  < map->rows)
	{
		lines[i] = get_next_line(fd);
		len = ft_strlen(lines[i]);
		if (len > 0 && lines[i][len - 1] == '\n')
			lines[i][len - 1] = '\0';
		i++;
	}
	lines[i] = NULL;
	return (lines);
}

int check_size_map(t_map *map)
{
	int 	i;
	size_t	line_length;

	line_length = ft_strlen(map->copy_map[0]);
	i = 0;
	while (map->copy_map[i])
	{
		if (line_length != ft_strlen(map->copy_map[i]))
			return (0);
		i++;
	}
	map->columns = (int)line_length;
	return (1);
}
int	check_all_chars(t_map *map)
{
	int i;
	int	j;

	i = 0;
	while (map->copy_map[i])
	{
		j = 0;
		while (map->copy_map[i][j])
		{
			if (map->copy_map[i][j] != 'P' && map->copy_map[i][j] != 'C' && map->copy_map[i][j] != 'E'
				&& map->copy_map[i][j] != '0' && map->copy_map[i][j] != '1' && map->copy_map[i][j] != '\n')
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
	if (map->copy_map[x][y] != '0' && map->copy_map[x][y] != 'C' && map->copy_map[x][y] != 'P')
		return ;
	map->copy_map[x][y] = 'V';
	flood_fill_rec(map, x + 1, y);
	flood_fill_rec(map, x - 1, y);
	flood_fill_rec(map, x, y + 1);
	flood_fill_rec(map, x, y - 1);
}

int	check_flood_fill(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->copy_map[i])
	{
		j = 0;
		while (map->copy_map[i][j])
		{
			if (map->copy_map[i][j] != 'V' && map->copy_map[i][j] != '1' && map->copy_map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
			if (map->copy_map[x][y] == 'P')
			{
				flood_fill_rec(map, x, y);
				if (check_flood_fill(map))
					return (1);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int check_edges_map(t_map *map)
{
	int	(i), (j);

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while(j < map->columns)
		{
			if (i == 0 && map->copy_map[i][j] != '1')
				return (0);
			if (i == (map->rows - 1) && map->copy_map[map->rows - 1][j] != '1')	
				return (0);
			if (j == 0 && map->copy_map[i][j] != '1')
				return (0);
			if (j == (map->columns - 1)  && map->copy_map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(char *filename, t_map *map)
{
	int	fd;
	fd = open(filename, O_RDONLY);
	if (!check_valid_character(fd, map))
		return (0);
	map->copy_map = read_map(fd, map, filename);
	if (!map->copy_map)
		return (0);
	if (!check_size_map(map))
		return (free_array(map->copy_map, map->rows), 0);
	if (!check_all_chars(map))
		return (free_array(map->copy_map, map->rows), 0);
	if (!flood_fill(map))
		return (free_array(map->copy_map, map->rows), 0);
	if (!check_edges_map(map))
		return (free_array(map->copy_map, map->rows), 0);
	map->map = read_map(fd, map, filename);
	free_array(map->copy_map, map->rows);
	return (1);
}
