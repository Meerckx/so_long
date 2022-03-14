/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:39:40 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:42:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	int		rem;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		rem = 0;
	if (ft_strlen(s) >= len + start)
		rem = len;
	subs = (char *)malloc(sizeof(char) * (rem + 1));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return (subs);
}
