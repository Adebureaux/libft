/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:09:45 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/18 22:32:20 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_itoa_len(int n)
{
	int		len;

	len = 1;
	n < 0 ? len++ : 0;
	while ((n /= 10))
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dst;
	long	lgn;
	int		len;

	len = ft_itoa_len(n);
	if (!(dst = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	lgn = n;
	lgn < 0 ? dst[0] = '-' : 0;
	lgn < 0 ? lgn *= -1 : 0;
	dst[len] = '\0';
	while (len-- && dst[len] != '-')
	{
		dst[len] = lgn % 10 + '0';
		lgn /= 10;
	}
	return (dst);
}
