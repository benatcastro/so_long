/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:52:16 by bena              #+#    #+#             */
/*   Updated: 2022/04/27 14:54:23 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	find_len;

	if (!*s2)
		return ((char *)(s1));
	find_len = ft_strlen(s2);
	index = 0;
	while (s1[index] && index < n)
	{
		if (find_len + index > n)
			return (NULL);
		if (s1[index] == s2[0] && ft_strncmp(&s1[index], s2, find_len) == 0)
			return ((char *)&s1[index]);
		index++;
	}
	return (NULL);
}
