/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:26:41 by bena              #+#    #+#             */
/*   Updated: 2022/07/17 17:29:17 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*n_str;

	i = -1;
	j = -1;
	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	n_str = malloc(ft_strlen_gnl(str1) + ft_strlen_gnl(str2) + 1);
	if (!n_str)
		return (NULL);
	while (str1[++i])
		n_str[i] = str1[i];
	while (str2[++j])
		n_str[i + j] = str2[j];
	n_str[j + i] = '\0';
	free(str1);
	return (n_str);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter])
		counter++;
	return (counter);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*str;
	int		i;
	size_t	len;

	len = ft_strlen_gnl(s1);
	i = -1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++i < (int)len)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

void	ft_free_node(t_fd **head, t_fd *node)
{
	t_fd	*aux;

	if ((*head) == node)
	{
		aux = node;
		(*head) = (*head)->next;
		free(aux);
	}
	else
	{
		aux = (*head);
		while (aux)
		{
			if (aux->next == node)
			{
				aux->next = node->next;
				break ;
			}
			aux = aux->next;
		}
		free(node);
	}
}
