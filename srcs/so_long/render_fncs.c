/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/23 22:43:43 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"

int	ft_render_frame(void *data)
{
	t_frame		*frame;
	int			i;
	void		*img1;
	void		*img2;

	frame = data;
	img1 = mlx_xpm_file_to_image(frame->mlx_ptr, IMG_COLOR1, &i, &i);
	img2 = mlx_xpm_file_to_image(frame->mlx_ptr, IMG_COLOR2, &i, &i);
	mlx_put_image_to_window(frame->mlx_ptr, frame->mlx_win, img1, 0, 0);
	mlx_put_image_to_window(frame->mlx_ptr, frame->mlx_win, img2, 128, 0);
	return (1);
}
