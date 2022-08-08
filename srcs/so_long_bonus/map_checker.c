/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:56:49 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 03:54:07 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
/*
Parsing of every line of the map looking for any invalid wall position
Also checks for any invalid character in the map
And defines the width of the map based on the first line
*/
static void	ft_parse_walls(t_map *map_data, char *map_line)
{
	int			len;
	static int	line;
	int			i;

	i = -1;
	len = ft_len_to_char(map_line, '\n');
	if (len != map_data->width && line != 0)
		ft_map_errors(3, map_line);
	while (map_line[++i] && map_line[i] != '\n')
	{
		if (!ft_is_in_set(map_line[i], "10PCE"))
			ft_map_errors(4, map_line);
		if (line == 0 || line == map_data->height)
		{
			if (map_line[i] != '1')
				ft_map_errors(1, map_line);
		}
		if (map_line[0] != '1' || map_line[len] != '1')
			ft_map_errors(2, map_line);
	}
	if (line == 0)
		map_data->width = len;
	line++;
}

/*
Checks if the map has all the utils needed to be played:
1 - characters
1 - exit point
1 < Collectables
and how enemies are in the map
*/
static void	ft_parse_utils(t_map *map_data, char *map_line)
{
	static int	lines;
	int			i;

	i = -1;
	while (map_line[++i])
	{
		if (map_line[i] == 'P')
			map_data->character++;
		else if (map_line[i] == 'E')
			map_data->exit++;
		else if (map_line[i] == 'C')
			map_data->collectables++;
		else if (map_line[i] == 'X')
			map_data->enemies++;
	}
	lines++;
	if (lines == map_data->height)
	{
		if (map_data->character != 1)
			ft_uitls_errors(0);
		if (map_data->exit != 1)
			ft_uitls_errors(1);
		if (map_data->collectables == 0)
			ft_uitls_errors(2);
	}
}

/*
Defines map heigt by the iterations of GNL fnc to return null
*/
static void	ft_get_map_height(t_map *map_data)
{
	char	*map_line;
	int		check;

	check = 0;
	map_line = NULL;
	while (map_line || check == 0)
	{
		check = 1;
		map_line = get_next_line(map_data->fd);
		if (map_line)
			map_data->height++;
		free(map_line);
	}
	if (map_data->height <= 0)
		ft_map_errors(0, map_line);
}

/*Splits the map in lines and calls to the functions needed to parse the lines*/
static void	ft_get_map_lines(t_map *map_data)
{
	char	*map_line;
	int		check;

	check = 0;
	map_line = NULL;
	while (map_line || check == 0)
	{
		check = 1;
		map_line = get_next_line(map_data->fd);
		if (map_line)
		{
			ft_parse_walls(map_data, map_line);
			ft_parse_utils(map_data, map_line);
		}
		free(map_line);
	}
}

/*
Takes the relative path to the map as argument
Initializes map_data struct
Calls the functions needed to check if the map is valid or not
Return value:
The structure map_data itself filled with information of the map
*/
t_map	ft_validate_map(char *map_path)
{
	t_map	map_data;

	map_data.path = map_path;
	map_data.character = 0;
	map_data.exit = 0;
	map_data.enemies = 0;
	map_data.collectables = 0;
	map_data.valid_walls = 0;
	map_data.width = 0;
	map_data.height = -1;
	map_data.fd = open(map_path, O_RDONLY);
	ft_get_map_height(&map_data);
	close(map_data.fd);
	map_data.fd = open(map_path, O_RDONLY);
	ft_get_map_lines(&map_data);
	close(map_data.fd);
	return (map_data);
}
