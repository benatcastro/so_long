/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:30:59 by bena              #+#    #+#             */
/*   Updated: 2022/04/27 08:36:36 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_sub_size(char const *s, char c);
size_t		ft_count_substrs(char const *s, char c);
const char	*ft_next_word(const char *s, char c);
char		*ft_strldup(const char *s1, size_t len);

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	if (!s)
		return (NULL);
	str = malloc(ft_count_substrs(s, c) * sizeof(char *));
	if (!str)
		return (NULL);
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[count++] = ft_strldup(s, ft_sub_size(s, c));
			s = ft_next_word(s, c);
			if (*s == 0)
				break ;
		}
		s++;
	}
	str[count] = 0;
	return (str);
}

const char	*ft_next_word(const char *s, char c)
{
	while (*s != 0 && *s != c)
		s++;
	return (s);
}

size_t	ft_sub_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && s[1] != c)
	{
		i++;
		s++;
	}
	return (i + 1);
}

size_t	ft_count_substrs(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if ((s[1] == c || s[1] == '\0') && *s != c)
			count++;
		s++;
	}
	return (count + 1);
}

char	*ft_strldup(const char *s1, size_t len)
{
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
