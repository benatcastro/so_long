/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:46:27 by becastro          #+#    #+#             */
/*   Updated: 2022/07/12 23:54:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstadd_back(t_fd **lst, t_fd *new)
{
	t_fd	*iterate;

	if (new)
	{
		if (!(*lst))
		{
			(*lst) = new;
			return ;
		}
		iterate = (*lst);
		while (iterate->next)
			iterate = iterate->next;
		iterate->next = new;
	}
}

static	t_fd	*ft_create_node(int fd, t_fd **head)
{
	t_fd	*node;

	node = malloc(sizeof(t_fd));
	node->fd = fd;
	node->str = NULL;
	node->next = NULL;
	ft_lstadd_back(head, node);
	return (node);
}

static	t_fd	*ft_get_node(int fd, t_fd **node)
{
	t_fd	*tmp;

	if (!(*node))
		(*node) = ft_create_node(fd, node);
	tmp = (*node);
	while ((tmp))
	{
		if ((tmp)->fd == fd)
			return (tmp);
		(tmp) = (tmp)->next;
	}
	if (!(tmp))
		(tmp) = ft_create_node(fd, node);
	return ((tmp));
}

static	int	get_str(int fd, t_fd *node, int rd)
{
	char	*buffer;
	char	*aux;

	buffer = malloc(sizeof(char *));
	node->str = malloc(1);
	node->str[0] = 0;
	while (rd > 0)
	{
		rd = read(fd, buffer, 1);
		if (rd <= 0 && node->str[0] == 0)
		{
			free(buffer);
			return (1);
		}
		else if (rd == 0)
			break ;
		buffer[1] = 0;
		aux = ft_strjoin(node->str, buffer);
		node->str = ft_strdup(aux);
		free(aux);
		if (node->str[ft_strlen(node->str) - 1] == '\n' )
			break ;
	}
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_fd		*node;
	t_fd			*aux;
	int				eof;

	aux = node;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = ft_get_node(fd, &node);
	eof = get_str(fd, aux, 1);
	if (eof == 1)
	{
		free(aux->str);
		printf("freeing node (%d)\n", aux->fd);
		ft_free_node(&node, aux);
		return (NULL);
	}
	if ((aux)->str[0] == 0 || eof == 1)
		return (NULL);
	return ((aux)->str);
}
