/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:01 by becastro          #+#    #+#             */
/*   Updated: 2022/07/18 16:46:12 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	mlx_data;
	t_map	map_data;

	if (argc != 2)
		return (0);
	map_data = ft_validate_map(argv[1]);
	mlx_data.win_id = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.win_id, (IMAGE_RES * map_data.width),
			(IMAGE_RES * map_data.height), "so_long");
	mlx_key_hook(mlx_data.win, ft_key_hooks, NULL);
	mlx_hook(mlx_data.win, 17, 1L << 17, ft_key_hooks, NULL);
	mlx_loop(mlx_data.win_id);
}
