/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:13:37 by ppoti             #+#    #+#             */
/*   Updated: 2022/09/24 13:06:15 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_chain;
	t_list	*chain;

	head_chain = NULL;
	while (lst)
	{
		chain = ft_lstnew((*f)(lst->content));
		if (!chain)
		{
			ft_lstclear(&head_chain, del);
			return (0);
		}
		ft_lstadd_back(&head_chain, chain);
		lst = lst->next;
	}
	return (head_chain);
}
