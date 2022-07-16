/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:46:50 by becastro          #+#    #+#             */
/*   Updated: 2022/04/25 12:27:56 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*aux;

	if (!*f && !*del && !lst)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		aux = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&newlst, aux);
		lst = lst->next;
	}
	return (newlst);
}
