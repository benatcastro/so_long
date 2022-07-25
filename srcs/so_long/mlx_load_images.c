/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/25 23:18:29 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "so_long.h"

void	ft_load_floor(t_program_data *data)
{
	int			res;

	res = IMG_RES;
	data->floor = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/blue_test.xpm", &res, &res);
}

void	ft_load_w_edges(t_program_data *data)
{
	int			res;

	res = IMG_RES;
	data->w_edges.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/red_test.xpm", &res, &res);
	data->w_edges.tex[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/test1.xpm", &res, &res);
}

void	ft_load_character(t_program_data *data)
{
	int			res;

	res = IMG_RES;
	data->player.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/green_test.xpm", &res, &res);
	data->player.tex[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/blue_test.xpm", &res, &res);
}

void	ft_load_textures(t_program_data *data)
{
	ft_load_w_edges(data);
	ft_load_character(data);
}
