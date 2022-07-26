/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/26 04:35:09 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "so_long.h"

void	ft_load_floor(t_program_data *data)
{
	int	res;

	res = IMG_RES;
	data->floor.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/floor/white_tile.xpm", &res, &res);
}

void	ft_load_walls(t_program_data *data)
{
	int	res;

	data->walls.edges_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/edge_north.xpm", &res, &res);
	data->walls.edges_tex[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/edge_south.xpm", &res, &res);
	data->walls.edges_tex[2] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/edge_east.xpm", &res, &res);
	data->walls.edges_tex[3] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/edge_west.xpm", &res, &res);
	data->walls.edges_tex[4] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/corner_top_left.xpm", &res, &res);
	data->walls.edges_tex[5] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/edges/corner_top_right.xpm", &res, &res);
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
}
