/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:57:55 by bena              #+#    #+#             */
/*   Updated: 2022/04/27 14:54:31 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_check_in_set(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0')
	{
		if (!(ft_check_in_set(s1[start], set)))
			break ;
		start++;
	}
	end = ft_strlen(s1);
	while (end--)
	{
		if (!(ft_check_in_set(s1[end], set)))
			break ;
	}
	str = ft_substr(s1, start, (end - start) + 1);
	return (str);
}

unsigned int	ft_check_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
// int	main(void)
// {
// 	char *s = ft_strtrim(""   xxx   xxx"", " x");
// 	printf("%s", s);
// }
