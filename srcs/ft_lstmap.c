/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:29:05 by adeburea          #+#    #+#             */
/*   Updated: 2020/09/30 20:10:13 by augustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*elem;

	dst = NULL;
	while (lst && f)
	{
		if (!(elem = ft_lstnew(f(&lst->content))))
		{
			ft_lstclear(&dst, del);
			break ;
		}
		ft_lstadd_back(&dst, elem);
		lst = lst->next;
	}
	return (dst);
}
