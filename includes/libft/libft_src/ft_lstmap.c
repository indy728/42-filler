/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:42:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/24 00:04:41 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *scout;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	scout = lst;
	head = ft_lstnew(f(scout)->content, f(scout)->content_size);
	new = head;
	while (scout->next != NULL)
	{
		scout = scout->next;
		new->next = ft_lstnew(f(scout)->content, f(scout)->content_size);
		new = new->next;
	}
	return (head);
}
