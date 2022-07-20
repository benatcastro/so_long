/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/20 05:07:02 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render_frame(void *data)
{
	t_frame		*frame;
	(void)frame;

	frame = data;
	//mlx_put_image_to_window(frame->mlx_ptr,
	//	frame->mlx_win, frame->player.tex[0], 0, 0);
	return (1);
}
