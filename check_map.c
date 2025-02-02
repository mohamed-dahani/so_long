/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:05:17 by mdahani           #+#    #+#             */
/*   Updated: 2025/02/02 18:53:16 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "helper-functions/get_next_line/get_next_line.h"


// int check_rectangle(char *str)
// {
//     //check nafes size 
// }
static int check_valid_charcter(int fd, t_map *map)
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
// int flood_fill()
// {
//     // check 0
// }
char **read_map(int fd, int rows, char  *filename)
{
	char 	**lines;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	lines = malloc(sizeof(char *) * (rows + 1));
	if (!lines)
		return NULL;
	while (i  < rows)
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
	return (1);
}
void print_map(char **map, int rows)
{
	for(int i = 0; i < rows; i++)
	{
		printf("%s", map[i]);
	}
}
int	check_map(char *filename, t_map *map)
{
	int	fd;
	fd = open(filename, O_RDONLY);
	if (!check_valid_charcter(fd, map))
		return (0);
	map->map = read_map(fd, map->rows, filename);
	if (!map->map)
		return (0);
	if (!check_size_map(map))
		return (free_array(map->map, map->rows), 0);
	print_map(map->map, map->rows);
	free_array(map->map, map->rows);
	return (1);
}
