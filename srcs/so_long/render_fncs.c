/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/24 23:22:04 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"

int	ft_render_frame(void *render_data)
{
	static int		frame;
	t_program_data	*data;

	data = render_data;
	printf("\n------RENDER------");
	printf("PTR (%p)\nTEX (%p)\n", data->mlx.ptr, data->player.tex[0]);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->player.tex[0], 0, 0);
	frame++;
	return (frame);
}
