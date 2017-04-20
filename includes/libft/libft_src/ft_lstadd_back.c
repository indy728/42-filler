/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:31:38 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/19 18:57:17 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*scout;

	if (new)
	{
		if (*alst)
		{
			scout = *alst;
			while (scout->next)
				scout = scout->next;
			scout->next = new;
		}
		else
			*alst = new;
	}
}
