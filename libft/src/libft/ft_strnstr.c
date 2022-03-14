/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:27:19 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:42:26 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	hlen;
	size_t	nlen;

	i = 0;
	if (!haystack || !needle)
		return (NULL);
	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	if (!nlen)
		return ((char *)haystack);
	while (haystack[i] && len - i >= nlen && hlen - i >= nlen)
	{
		if (!ft_strncmp(&haystack[i], needle, nlen))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
