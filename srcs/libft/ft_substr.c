/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:12:44 by bena              #+#    #+#             */
/*   Updated: 2022/04/27 14:54:36 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(1);
		*str = '\0';
		return (str);
	}
	str = NULL;
	s += start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(len + 1);
	if (!(str))
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

// int	main(void)
// {
// 	// char	*s = "tripouille";
// 	printf("%s \n", ft_substr("tripouille", 100, 1));
// }
