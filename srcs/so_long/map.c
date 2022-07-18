/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:56:49 by becastro          #+#    #+#             */
/*   Updated: 2022/07/18 04:19:38 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_parse_walls(t_map *map_data, char *map_line)
{
	int			len;
	static int	line;
	int			i;

	i = -1;
	len = ft_len_to_char(map_line, '\n');
	if (len != map_data->width && line != 0)
		ft_map_errors(3);
	while (map_line[++i] && map_line[i] != '\n')
	{
		if (!ft_is_in_set(map_line[i], "10PCE"))
			ft_map_errors(4);
		if (line == 0 || line == map_data->height)
		{
			if (map_line[i] != '1')
				ft_map_errors(1);
		}
		if (map_line[0] != '1' || map_line[len] != '1')
			ft_map_errors(2);
	}
	if (line == 0)
		map_data->width = len;
	line++;
}

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
		ft_map_errors(0);
}

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
			ft_parse_walls(map_data, map_line);
		free(map_line);
	}
}

// static int	ft_check_walls(t_map map_data, char *map_line)
// {
// 	int	i;

// 	(void)map_data;
// 	i = -1;
// 	while (map_line[++i])
// 	{
// 		if (map_line[i] != '1')
// 		{
// 			perror("Walls error");
// 			exit(EXIT_FAILURE);
// 		}
// 	}
// 	return (1);
// }



int	ft_validate_map(char *map_path)
{
	t_map	map_data;

	map_data.character = 0;
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
	//printf("HEIGHT: (%d)\n", map_data.height);
	return (1);
}
