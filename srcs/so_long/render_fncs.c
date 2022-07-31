/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/08/01 00:40:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"


/*Direction render player facing East*/
static void	ft_render_player(t_program_data *data)
{
	if (data->player.direction == 'E')
		mlx_put_image_to_window(data->mlx.ptr,
			data->mlx.win, data->player.tex[1],
			data->player.x, data->player.y);
	else if (data->player.direction == 'N' || data->player.direction == 'S')
		mlx_put_image_to_window(data->mlx.ptr,
			data->mlx.win, data->player.tex[2],
			data->player.x, data->player.y);
	else
		mlx_put_image_to_window(data->mlx.ptr,
			data->mlx.win, data->player.tex[0],
			data->player.x, data->player.y);
}

int	ft_render_frame(void *render_data)
{
	static int		frame;
	t_program_data	*data;

	data = render_data;
	ft_render_map(data);
	ft_put_collectables(data);
	ft_render_player(data);
	usleep(90000);

	frame++;
	return (frame);
}
