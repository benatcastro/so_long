/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:15:04 by becastro          #+#    #+#             */
/*   Updated: 2022/07/20 04:37:57 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "keys.h"
# include "mlx.h"
# include "get_next_line_bonus.h"

# define IMG_RES 128

typedef struct s_data {
	void	*ptr;
	void	*win;
	char	*addr;
	int		bits_pix;
	int		len_line;
	int		endian;
}	t_data;

typedef struct s_map {
	int		fd;
	int		character;
	int		exit;
	int		enemies;
	int		collectables;
	int		valid_walls;
	int		width;
	int		height;
}	t_map;

typedef struct s_character
{
	void	*tex[3];
	int		x;
	int		y;
}	t_character;

typedef struct s_frame
{
	void				*mlx_ptr;
	void				*mlx_win;
	struct s_character	player;
}	t_frame;

int		ft_key_hooks(int key);
t_map	ft_validate_map(char *map_path);
void	ft_map_errors(int error_key);
void	ft_uitls_errors(int error_key);
/************************Mlx Functions******************************/

void	ft_load_textures(t_data *mlx, t_frame *frame);

/************************Render FNCS******************************/
int		ft_render_frame(void *data);

#endif
