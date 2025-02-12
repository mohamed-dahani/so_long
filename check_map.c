/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:05:17 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/12 20:48:17 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper-functions/get_next_line/get_next_line.h"
#include "includes/so_long.h"

static void	check_chars(t_map *map, char *line, int *char_not_valid)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			map->_0++;
		else if (line[i] == '1')
			map->_1++;
		else if (line[i] == 'P')
			map->p++;
		else if (line[i] == 'C')
			map->c++;
		else if (line[i] == 'N')
			map->n++;
		else if (line[i] == 'E')
			map->e++;
		else if (line[i] != '\n')
			(*char_not_valid)++;
		i++;
	}
}

static int	check_valid_character(int fd, t_map *map)
{
	char	*line;
	int		char_not_valid;

	map->rows = 0;
	char_not_valid = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_chars(map, line, &char_not_valid);
		map->rows++;
		free(line);
	}
	close(fd);
	return (map->_0 && map->_1 && map->p == 1 && map->c && map->n && map->e == 1
		&& char_not_valid == 0);
}

static char	**read_map(int fd, t_map *map, char *filename)
{
	char	**lines;
	int		i;
	int		len;

	i = 0;
	fd = open(filename, O_RDONLY);
	lines = malloc(sizeof(char *) * (map->rows + 1));
	if (!lines)
		return (NULL);
	while (i < map->rows)
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

static int	check_size_map(t_map *map)
{
	int		i;
	size_t	line_length;

	line_length = ft_strlen(map->copy_map[0]);
	i = 0;
	while (map->copy_map[i])
	{
		if (line_length != ft_strlen(map->copy_map[i]))
			return (0);
		i++;
	}
	if (i > 32 || line_length > 60 || i == (int)line_length)
		return (0);
	map->columns = (int)line_length;
	return (1);
}

int	check_map(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	map->_0 = 0;
	map->_1 = 0;
	map->p = 0;
	map->c = 0;
	map->n = 0;
	map->e = 0;
	if (!check_valid_character(fd, map))
		return (0);
	map->copy_map = read_map(fd, map, filename);
	if (!map->copy_map)
		return (0);
	if (!check_size_map(map))
		return (free_array(map->copy_map, map->rows), 0);
	if (!flood_fill(map))
		return (free_array(map->copy_map, map->rows), 0);
	if (!check_edges_map(map))
		return (free_array(map->copy_map, map->rows), 0);
	map->map = read_map(fd, map, filename);
	free_array(map->copy_map, map->rows);
	return (1);
}
