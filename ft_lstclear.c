/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:57:39 by adeburea          #+#    #+#             */
/*   Updated: 2020/09/30 20:43:03 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

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
