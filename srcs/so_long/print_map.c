/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:01 by becastro          #+#    #+#             */
/*   Updated: 2022/07/26 05:50:11 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_read_len(char *path)
{
	int		rd;
	int		fd;
	size_t	i;
	char	*buffer;

	i = 0;
	rd = 1;
	buffer = malloc(1);
	fd = open (path, O_RDONLY);
	while (rd != 0)
	{
		rd = read(fd, buffer, 1);
		i++;
	}
	free(buffer);
	close(fd);
	return (i);
}

void	ft_print_floor(char **map, t_program_data *data)
{
	int	i;
	int	j;
	int	pos[2];

	pos[1] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		pos[0] = 0;
		while (map[i][++j])
		{
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
				data->floor.tex[0], pos[0], pos[1]);
			pos[0] += IMG_RES;
		}
		pos[1] += IMG_RES;
	}
	free (map);
}

void	ft_print_edges_south(char **map, t_program_data *data)
{
	int	i;
	int	y;
	int	x;

	y = IMG_RES * data->map->height + 1;
	x = 0;
	i = -1;
	while (map[data->map->height][++i])
	{
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
			data->walls.edges_tex[0], x, y);
		x += IMG_RES;
	}
	free(map);
}

void	ft_print_edges_north(char **map, t_program_data *data)
{
	int	i;
	int	x;

	x = 0;
	i = -1;
	while (map[0][++i])
	{
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
			data->walls.edges_tex[1], x, 0);
		x += IMG_RES;
	}
	free(map);
}

void	ft_render_map(t_program_data *data)
{
	size_t	map_len;
	char	*map_str;
	int		fd;

	map_len = ft_read_len(data->map->path);
	map_str = malloc(map_len);
	fd = open(data->map->path, O_RDONLY);
	read (fd, map_str, (int)map_len);
	close(fd);
	ft_print_floor(ft_split(map_str, '\n'), data);
	ft_print_edges_north(ft_split(map_str, '\n'), data);
	ft_print_edges_south(ft_split(map_str, '\n'), data);
	ft_print_sides(ft_split(map_str, '\n'), data);
	ft_print_corners_north(ft_split(map_str, '\n'), data);
	ft_print_corners_south(ft_split(map_str, '\n'), data);
}
