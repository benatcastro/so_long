/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/20 04:39:54 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render_frame(void *data)
{
	t_character	player;
	t_frame		*frame;

	frame = data;
	// mlx_put_image_to_window(frame->mlx_ptr,
	// 	frame->mlx_win, player.tex[0], 0, 0);
	(void)player;
	(void)frame;
	return (1);
}
