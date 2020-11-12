/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:01:41 by adeburea          #+#    #+#             */
/*   Updated: 2020/09/30 20:43:01 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if ((*alst))
	{
		last = ft_lstlast((*alst));
		last->next = new;
		new->next = NULL;
	}
	else
		(*alst) = new;
}
