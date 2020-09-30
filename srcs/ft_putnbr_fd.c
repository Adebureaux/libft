/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:09:49 by adeburea          #+#    #+#             */
/*   Updated: 2020/09/30 20:04:26 by augustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	lgn;

	lgn = n;
	lgn < 0 ? lgn = -lgn : 0;
	lgn < 0 ? write(fd, "-", 1) : 0;
	if (lgn >= 10)
	{
		ft_putnbr_fd(lgn / 10, fd);
		ft_putnbr_fd(lgn % 10, fd);
	}
	else
	{
		c = lgn + '0';
		write(fd, &c, 1);
	}
}
