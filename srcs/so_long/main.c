/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:01 by becastro          #+#    #+#             */
/*   Updated: 2022/07/27 09:33:47 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_window(int width, int height, t_map *map_data)
{
	t_program_data	data;

	data.map = map_data;
	data.mlx.ptr = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.ptr, width, height, "so_long");
	ft_load_textures(&data);
	ft_render_map(&data);
	ft_put_player(&data);
	mlx_key_hook(data.mlx.win, ft_key_hooks, &data.player);
	mlx_hook(data.mlx.win, 17, 1L << 17, ft_key_hooks, NULL);
	mlx_loop_hook(data.mlx.ptr, ft_render_frame, &data);
	mlx_loop(data.mlx.ptr);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (0);
	map.path = argv[1];
	map = ft_validate_map(map.path);
	ft_init_window((map.width + 1) * IMG_RES, (map.height + 1) * IMG_RES, &map);
}
