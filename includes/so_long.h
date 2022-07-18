/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:15:04 by becastro          #+#    #+#             */
/*   Updated: 2022/07/18 04:09:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "keys.h"
# include "mlx.h"
# include "get_next_line_bonus.h"

typedef struct t_data {
	void	*win_id;
	void	*win;
	char	*addr;
	int		bits_pix;
	int		len_line;
	int		endian;
}				t_data;

typedef struct t_map {
	int		fd;
	int		character;
	int		collectables;
	int		valid_walls;
	int		width;
	int		height;
}	t_map;

int		ft_key_hooks(int key);
int		ft_validate_map(char *map_path);
void	ft_map_errors(int error_key);

#endif
