/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:59:47 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:42:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	ft_memstr(char const *s1, char const *s2, char *new_str)
{
	size_t	new_len;

	new_len = 0;
	if (s1)
	{
		while (*s1)
			new_str[new_len++] = *s1++;
	}
	if (s2)
	{
		while (*s2)
			new_str[new_len++] = *s2++;
	}
	new_str[new_len] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*new_str;

	lens1 = 0;
	lens2 = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		lens1 = ft_strlen(s1);
	if (s2)
		lens2 = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!new_str)
		return (NULL);
	ft_memstr(s1, s2, new_str);
	return (new_str);
}
