/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_fncs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 03:51:52 by becastro          #+#    #+#             */
/*   Updated: 2022/07/29 22:38:53 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_sides(t_program_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map->map_str;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (j == 0)
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.edges_tex[2], j * IMG_RES, i * IMG_RES);
			if (j == data->map->width)
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.edges_tex[3], j * IMG_RES, i * IMG_RES);
		}
	}
}

void	ft_print_corners_south(t_program_data *data)
{
	int		i;
	int		x;
	int		y;
	char	**map;

	map = data->map->map_str;
	y = IMG_RES * data->map->height;
	x = 0;
	i = -1;
	while (map[data->map->height][++i])
	{
		if (i == 0)
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
				data->walls.edges_tex[6], x, y);
		else if (i == data->map->width)
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
				data->walls.edges_tex[7], x, y);
		x += IMG_RES;
	}
}

void	ft_print_corners_north(t_program_data *data)
{
	int		i;
	int		x;
	char	**map;

	map = data->map->map_str;
	x = 0;
	i = -1;
	while (map[0][++i])
	{
		if (i == 0)
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
				data->walls.edges_tex[4], x, 0);
		else if (i == data->map->width)
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
				data->walls.edges_tex[5], x, 0);
		x += IMG_RES;
	}
}

void	ft_print_inside_walls(t_program_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map->map_str;
	i = 0;
	while (map[++i] && i < data->map->height)
	{
		j = 0;
		while (map[i][++j] && j < data->map->width)
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.walls_tex[0], j * IMG_RES, i * IMG_RES);
			if (map[i + 1][j] == '1'
				&& (i + 1 == data->map->height && map[i][j] == '1'))
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.walls_tex[0], j * IMG_RES, (i + 1) * IMG_RES);
			if (map[i - 1][j] == '1'
				&& (i - 1 == 0 && map[i][j] == '1'))
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.walls_tex[0], j * IMG_RES, (i - 1) * IMG_RES);
		}
	}
}

void	ft_print_inside_walls_sides(t_program_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map->map_str;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j + 1] == '1'
				&& (j + 1 == data->map->width && map[i][j] == '1'))
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.walls_tex[0], (j + 1) * IMG_RES, i * IMG_RES);
			if (map[i][j - 1] == '1'
				&& (j - 1 == 0 && map[i][j] == '1'))
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.walls_tex[0], (j - 1) * IMG_RES, i * IMG_RES);
		}
	}
}
