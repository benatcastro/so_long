/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/25 00:08:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "so_long.h"

void	ft_load_character(t_program_data *data)
{
	int			res;

	res = IMG_RES;

	data->player.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/red_test.xpm", &res, &res);
	data->player.tex[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/green_test.xpm", &res, &res);
	data->player.tex[2] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/blue_test.xpm", &res, &res);
}

void	ft_load_textures(t_program_data *data)
{
	ft_load_character(data);
}
