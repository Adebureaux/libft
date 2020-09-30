/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 00:14:14 by adeburea          #+#    #+#             */
/*   Updated: 2020/09/28 20:43:37 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t nee_len;

	if (!*needle || haystack == needle)
		return ((char*)haystack);
	nee_len = ft_strlen(needle);
	while (*haystack && --len > nee_len)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, nee_len) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
