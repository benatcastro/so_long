/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:01 by becastro          #+#    #+#             */
/*   Updated: 2022/07/29 22:45:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_floor(t_program_data *data)
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
			mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
				data->floor.tex[0], pos[0], pos[1]);
			pos[0] += IMG_RES;
		}
		pos[1] += IMG_RES;
	}
}

void	ft_print_edges_south(t_program_data *data)
{
	int		i;
	int		y;
	int		x;
	char	**map;

	map = data->map->map_str;
	y = IMG_RES * data->map->height + 1;
	x = 0;
	i = -1;
	while (map[data->map->height][++i])
	{
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
			data->walls.edges_tex[0], x, y);
		x += IMG_RES;
	}
}

void	ft_print_edges_north(t_program_data *data)
{
	int		i;
	int		x;
	char	**map;

	map = data->map->map_str;
	x = 0;
	i = -1;
	while (map[0][++i])
	{
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
			data->walls.edges_tex[1], x, 0);
		x += IMG_RES;
	}
}

void	ft_render_map(t_program_data *data)
{
	ft_print_floor(data);
	ft_print_edges_north(data);
	ft_print_edges_south(data);
	ft_print_sides(data);
	ft_print_inside_walls(data);
	ft_print_inside_walls_sides(data);
	ft_print_corners_south(data);
	ft_print_corners_north(data);
}
