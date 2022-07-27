/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_fncs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:48:55 by becastro          #+#    #+#             */
/*   Updated: 2022/07/27 07:15:00 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_collectables(t_program_data *data)
{
	int		i;
	int		j;
	int		pos[2];
	char	**map;

	map = data->map->map_str;
	pos[1] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		pos[0] = 0;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->utils.collect_tex[0], pos[0], pos[1]);
			if (map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->utils.exit_tex[0], pos[0], pos[1]);
			pos[0] += IMG_RES;
		}
		pos[1] += IMG_RES;
	}
}
