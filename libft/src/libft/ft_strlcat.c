/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:41:50 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:42:09 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	slen;
	size_t	src_i;
	size_t	dst_i;

	if (!src || !dst)
		return (0);
	len = 0;
	slen = ft_strlen(src);
	src_i = 0;
	dst_i = 0;
	while (dst[dst_i] && dstsize > 0)
	{
		dst_i++;
		len++;
		dstsize--;
	}
	while (src[src_i] && dstsize > 1)
	{
		dst[dst_i++] = src[src_i++];
		dstsize--;
	}
	if (dstsize == 1 || !src[src_i])
		dst[dst_i] = '\0';
	return (slen + len);
}
