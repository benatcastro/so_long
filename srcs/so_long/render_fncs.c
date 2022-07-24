/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/25 00:11:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"

int	ft_render_frame(void *render_data)
{
	static int		frame;
	static int		i;
	t_program_data	*data;

	if (i == 2)
		i = 0;
	data = render_data;
	mlx_put_image_to_window(data->mlx.ptr,
		data->mlx.win, data->player.tex[i], 0, 0);
	i++;
	//printf("test (%d)\n", i);
	usleep(20000);
	frame++;
	return (frame);
}
