/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_fncs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 03:51:52 by becastro          #+#    #+#             */
/*   Updated: 2022/07/29 19:07:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_sides(t_program_data *data)
{
	int		i;
	int		j;
	int		pos[2];
	char	**map;

	map = data->map->map_str;
	pos[1] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		pos[0] = 0;
		while (map[i][++j])
		{
			if (j == 0)
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.edges_tex[2], pos[0], pos[1]);
			if (j == data->map->width)
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.edges_tex[3], pos[0], pos[1]);
			pos[0] += IMG_RES;
		}
		pos[1] += IMG_RES;
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
