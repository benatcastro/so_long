/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 04:07:50 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "so_long.h"

static void	ft_load_utils(t_program_data *data)
{
	int	res;

	res = IMG_RES;
	data->utils.collect_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/objects/barrel.xpm", &res, &res);
	data->utils.exit_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/objects/locker.xpm", &res, &res);
}

static void	ft_load_tiles(t_program_data *data)
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
	data->floor.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/tiles/industrial_floor.xpm", &res, &res);
}

static void	ft_load_character(t_program_data *data)
{
	int			res;

	res = IMG_RES;
	data->player.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/character/biker_W.xpm", &res, &res);
	data->player.tex[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/character/biker_E.xpm", &res, &res);
	data->player.tex[2] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/character/biker_N.xpm", &res, &res);
}

void	ft_load_textures(t_program_data *data)
{
	ft_load_tiles(data);
	ft_load_character(data);
	ft_load_utils(data);
}
