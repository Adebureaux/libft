/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 00:14:14 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/19 04:56:39 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	if (len < 1)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] && haystack[i] == needle[j] && i < len)
		{
			j++;
			i++;
		}
		if (!needle[j])
			return ((char*)haystack + (i - j));
		i++;
	}
	return (NULL);
}
