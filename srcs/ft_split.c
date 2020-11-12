/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 00:13:00 by adeburea          #+#    #+#             */
/*   Updated: 2020/11/12 18:47:58 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_split(char **dst)
{
	int i;

	i = 0;
	while (dst[i])
		free(dst[i++]);
	return (NULL);
}

int		ft_split_strs(const char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

int		*ft_split_chars(const char *str, char c, int str_nbr)
{
	int		*char_nbr;
	int		count;
	int		i;

	i = 0;
	if (!*str)
		return (0);
	if (!(char_nbr = (int*)malloc(sizeof(int) * str_nbr)))
		return (NULL);
	while (str_nbr--)
	{
		count = 0;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			str++;
			count++;
		}
		char_nbr[i++] = count;
	}
	return (char_nbr);
}

char	**ft_spliter(const char *str, char c, int *char_nbr, int str_nbr)
{
	char	**dst;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(dst = (char**)malloc(sizeof(char*) * (str_nbr + 1))))
		return (NULL);
	while (++i < str_nbr)
	{
		while (str[j] == c)
			j++;
		while (str[j] != c && str[j])
		{
			dst[i] = ft_substr(str, j, char_nbr[i]);
			j += char_nbr[i];
		}
	}
	dst[i] = 0;
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	char	**dst;
	int		*char_nbr;
	int		str_nbr;

	if (!s)
		return (NULL);
	str_nbr = ft_split_strs(s, c);
	if (!(char_nbr = ft_split_chars(s, c, str_nbr)))
	 	return (NULL);
	if (!(dst = ft_spliter(s, c, char_nbr, str_nbr)))
		return (ft_free_split(dst));
	free(char_nbr);
	return (dst);
}
