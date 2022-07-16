/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:26:41 by bena              #+#    #+#             */
/*   Updated: 2022/07/12 23:53:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *str1, char *str2)
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
	n_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
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

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter])
		counter++;
	return (counter);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	size_t	len;

	len = ft_strlen(s1);
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
		//printf("FIRST NODE FREE (%d) \n", aux->fd);
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
		//printf("NODE BEING FREE (%d)\n", node->fd);
		free(node);
	}
}
