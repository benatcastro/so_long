/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:15:04 by becastro          #+#    #+#             */
/*   Updated: 2022/07/20 01:18:12 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "keys.h"
# include "mlx.h"
# include "get_next_line_bonus.h"

# define IMG_RES 128

typedef struct t_data {
	void	*ptr;
	void	*win;
	char	*addr;
	int		bits_pix;
	int		len_line;
	int		endian;
}				t_data;

typedef struct t_map {
	int		fd;
	int		character;
	int		exit;
	int		enemies;
	int		collectables;
	int		valid_walls;
	int		width;
	int		height;
}	t_map;

int		ft_key_hooks(int key);
t_map	ft_validate_map(char *map_path);
void	ft_map_errors(int error_key);
void	ft_uitls_errors(int error_key);
/************************Mlx Functions******************************/
void	*ft_create_image(t_data *mlx_data, char *image_path);
#endif
