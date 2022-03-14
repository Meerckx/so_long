/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:31:43 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:41:42 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!src || !dst)
		return (dst);
	if ((unsigned char *)dst < (unsigned char *)src)
	{
		i = 0;
		while (len--)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			++i;
		}
	}
	else
	{
		i = len - 1;
		while (len--)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			--i;
		}
	}
	return (dst);
}
