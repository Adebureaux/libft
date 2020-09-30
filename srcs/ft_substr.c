/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 00:14:35 by adeburea          #+#    #+#             */
/*   Updated: 2020/09/28 20:43:27 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char *dst;

	while (start-- && *s)
		s++;
	if (!(dst = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
