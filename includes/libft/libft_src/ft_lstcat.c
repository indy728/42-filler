/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:56:22 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/05 14:54:36 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcat(t_list **alst, t_list *new)
{
	t_list *scout;

	if (*alst && new)
	{
		scout = *alst;
		while (scout->next != NULL)
			scout = scout->next;
		scout->next = new;
	}
	else
		*alst = new;
}
