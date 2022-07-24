/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/24 23:14:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "so_long.h"

void	ft_load_character(t_program_data *data)
{
	int			i;

	data->player.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/green_test.xpm", &i, &i);
	printf("TEX LOADED (%p)", data->player.tex[0]);
	//printf("test\n");
	// tex[1] = mlx_xpm_file_to_image(mlx->ptr, IMG_COLOR2,
	// 		(int *)IMG_RES, (int *)IMG_RES);
	// char_tex[2] = mlx_xpm_file_to_image(mlx->ptr, IMG_COLOR3,
	// 		(int *)IMG_RES, (int *)IMG_RES);
}

void	ft_load_textures(t_program_data *data)
{
	ft_load_character(data);
}
