/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:01 by becastro          #+#    #+#             */
/*   Updated: 2022/07/17 16:09:38 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ft_validate_map(argv[1]);
	// t_data	mlx_data;

	// mlx_data.win_id = mlx_init();
	// mlx_data.win = mlx_new_window(mlx_data.win_id, 1280, 720, "so_long");
	// mlx_key_hook(mlx_data.win, ft_key_hooks, NULL);
	// mlx_hook(mlx_data.win, 17, 1L << 17, ft_key_hooks, NULL);
	// mlx_loop(mlx_data.win_id);
}
