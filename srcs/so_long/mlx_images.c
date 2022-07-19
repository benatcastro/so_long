
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/17 15:25:42 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "so_long.h"

void	*ft_create_image(t_data *mlx_data, char *image_path)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx_data->ptr,
			image_path, (int *)IMG_RES, (int *)IMG_RES);
	printf("IMG (%p)", img);
	return (img);
}
