/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/29 23:39:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "so_long.h"

void	ft_load_floor(t_program_data *data)
{
	int	res;

	res = IMG_RES;
	data->floor.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/tiles/industrial_floor.xpm", &res, &res);
}

void	ft_load_utils(t_program_data *data)
{
	int	res;

	res = IMG_RES;
	data->utils.collect_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/objects/barrel_background.xpm", &res, &res);
	data->utils.exit_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/objects/locker_background.xpm", &res, &res);
}

void	ft_load_walls(t_program_data *data)
{
	int	res;

	data->walls.edges_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/walls/bot_edge.xpm", &res, &res);
	data->walls.edges_tex[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/walls/top_edge.xpm", &res, &res);
	data->walls.edges_tex[2] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/walls/left_edge.xpm", &res, &res);
	data->walls.edges_tex[3] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/walls/right_edge.xpm", &res, &res);
	data->walls.edges_tex[4] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/walls/top_left_corner.xpm", &res, &res);
	data->walls.edges_tex[5] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/walls/top_right_corner.xpm", &res, &res);
	data->walls.edges_tex[6] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/walls/bot_left_corner.xpm", &res, &res);
	data->walls.edges_tex[7] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/walls/bot_right_corner.xpm", &res, &res);
	data->walls.walls_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/walls/inside_wall.xpm", &res, &res);
}

void	ft_load_character(t_program_data *data)
{
	int			res;

	res = IMG_RES;
	data->player.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/red_test.xpm", &res, &res);
	data->player.tex[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/char_test1.xpm", &res, &res);
}

void	ft_load_textures(t_program_data *data)
{
	ft_load_walls(data);
	ft_load_character(data);
	ft_load_floor(data);
	ft_load_utils(data);
}
