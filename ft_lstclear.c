/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:57:39 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/13 02:17:20 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	tmp = (*lst);
	if (!lst)
		return ;
	while ((*lst) && del)
	{
		del((*lst)->content);
		free(*lst);
		(*lst) = (*lst)->next;
	}
	tmp->next = NULL;
}
