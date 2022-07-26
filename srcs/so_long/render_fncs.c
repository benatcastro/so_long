/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/26 01:48:44 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"

int	ft_render_frame(void *render_data)
{
	static int		frame;
	static int		i;
	t_program_data	*data;

	data = render_data;
	if (frame == 0)
	{
		data->player.x = 0;
		data->player.y = 0;
	}
	if (i == 2)
		i = 0;
	ft_render_map(data);
	mlx_put_image_to_window(data->mlx.ptr,
		data->mlx.win, data->player.tex[i],
		data->player.x, data->player.y);
	i++;
	//printf("test (%d)\n", i);
	// usleep(90000);
	frame++;
	return (frame);
}
