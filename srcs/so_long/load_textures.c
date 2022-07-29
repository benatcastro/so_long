/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/29 20:33:17 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "so_long.h"

void	ft_load_floor(t_program_data *data)
{
	int	res;

	res = IMG_RES;
	data->floor.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/floor/industrial_floor.xpm", &res, &res);
}

void	ft_load_utils(t_program_data *data)
{
	int	res;

	res = IMG_RES;
	data->utils.collect_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/blue_test.xpm", &res, &res);
	data->utils.exit_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/green_test.xpm", &res, &res);
}

void	ft_load_walls(t_program_data *data)
{
	int	res;

	data->walls.edges_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/bot_edge.xpm", &res, &res);
	data->walls.edges_tex[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/top_edge.xpm", &res, &res);
	data->walls.edges_tex[2] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/left_edge.xpm", &res, &res);
	data->walls.edges_tex[3] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/right_edge.xpm", &res, &res);
	data->walls.edges_tex[4] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/top_left_corner.xpm", &res, &res);
	data->walls.edges_tex[5] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/top_right_corner.xpm", &res, &res);
	data->walls.edges_tex[6] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/bot_left_corner.xpm", &res, &res);
	data->walls.edges_tex[7] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/bot_right_corner.xpm", &res, &res);
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
