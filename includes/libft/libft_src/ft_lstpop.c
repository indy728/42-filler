/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:12:38 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/24 20:40:35 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_lstpop(t_list **alst, t_list **begin_list)
{
	t_list	*scout;
	t_list	*trail;

	if (!begin_list || !alst)
		return (NULL);
	scout = *begin_list;
	while (scout != *alst && scout->next)
	{
		trail = scout;
		scout = scout->next;
	}
	if (scout != *alst)
		return (NULL);
	if (scout == *begin_list)
		*begin_list = scout->next;
	else
		trail->next = scout->next;
	return (alst);
}
