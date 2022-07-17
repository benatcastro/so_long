/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:56:49 by becastro          #+#    #+#             */
/*   Updated: 2022/07/17 22:08:33 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	ft_parse_map(t_map map_data, char *map_line)
{
	static int	line;
	int			i;
	int			len;

	len = ft_strlen(map_line) - 2;
	printf("test: %d|| %s \n", map_data.map_width, map_line);
	i = -1;
	if (map_data.map_width != len)
		printf("error3");
	if (map_line[0] != '1' || map_line[len] != '1')
		printf("Error2\n");
	while (map_line[++i] && i < len)
	{
		if (map_line[i] != '1' && line == 0)
		{
			printf("CHAR (%d) i (%d)", map_line[i], i);
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
	}
	if (line == 0)
	{
		printf("HELLO");
		map_data.map_width = len;
	}
	line++;
}

static void	ft_get_map_line(t_map map_data)
{
	char	*map_line;
	int		check;

	check = 0;
	map_line = NULL;
	while (map_line || check == 0)
	{
		check = 1;
		map_line = get_next_line(map_data.fd);
		if (map_line)
			ft_parse_map(map_data, map_line);
		free(map_line);
	}
}

int	ft_validate_map(char *map_path)
{
	t_map	map_data;

	map_data.fd = open(map_path, O_RDONLY);
	map_data.character = 0;
	map_data.collectables = 0;
	map_data.valid_walls = 0;
	map_data.map_width = 0;
	ft_get_map_line(map_data);
	return (1);
}
