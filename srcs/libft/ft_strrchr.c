/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:00:07 by becastro          #+#    #+#             */
/*   Updated: 2022/04/27 14:54:27 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				lenght;
	unsigned char	d;

	d = c;
	lenght = ft_strlen(s);
	while (lenght >= 0)
	{
		if (s[lenght] == d)
			return ((char *)&s[lenght]);
		lenght--;
	}
	return (0);
}
