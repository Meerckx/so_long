/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:44:38 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:41:53 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			ch;
	unsigned int	un;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		un = -n;
		write(fd, "-", 1);
	}
	else
		un = n;
	if (un >= 10)
		ft_putnbr_fd(un / 10, fd);
	ch = (un % 10) + '0';
	write(fd, &ch, 1);
}
