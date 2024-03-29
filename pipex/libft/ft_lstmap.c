/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:44:48 by sbartoul          #+#    #+#             */
/*   Updated: 2023/12/28 23:45:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;

	if (!lst || !del)
		return (0);
	node = ft_lstnew(f(lst->content));
	if (!node)
		return (0);
	temp = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		if (!node->next)
		{
			ft_lstclear(&temp, del);
			return (0);
		}
		node = node->next;
		lst = lst->next;
	}
	node->next = NULL;
	return (temp);
}
