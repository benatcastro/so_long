/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/20 04:41:38 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "so_long.h"

void	ft_load_character(t_data *mlx, t_frame *frame)
{
	frame->player.tex[0] = mlx_xpm_file_to_image(mlx->ptr,
			"textures/green_test.xpm",
			(int *)IMG_RES, (int *)IMG_RES);
	printf("IMG (%p)", frame->player.tex[0]);
	// char_tex[1] = mlx_xpm_file_to_image(mlx->ptr, IMG_COLOR2,
	// 		(int *)IMG_RES, (int *)IMG_RES);
	// char_tex[2] = mlx_xpm_file_to_image(mlx->ptr, IMG_COLOR3,
	// 		(int *)IMG_RES, (int *)IMG_RES);
}

void	ft_load_textures(t_data *mlx, t_frame *frame)
{
	ft_load_character(mlx, frame);
}
