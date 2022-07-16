/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:32:47 by becastro          #+#    #+#             */
/*   Updated: 2022/04/27 14:51:54 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	counter;
	char			*string;

	string = str;
	counter = 0;
	while (counter < n)
	{
		string[counter] = c;
		counter++;
	}
	return (str);
}
