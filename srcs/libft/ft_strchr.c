/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:07:56 by becastro          #+#    #+#             */
/*   Updated: 2022/04/27 14:58:45 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			counter;
	unsigned char	d;

	d = c;
	counter = 0;
	while (s[counter])
	{
		if (s[counter] == d)
			return ((char *)&s[counter]);
		counter++;
	}
	if (s[counter] == d)
		return ((char *)&s[counter]);
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 		char s[] = "tripouille";

// 	printf("str: %s",strchr(s, 't' + 256));
// }
