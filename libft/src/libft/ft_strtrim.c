/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:20:35 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:42:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_chcmp(char const *set, char ch)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s1_trim;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_chcmp(set, s1[start]))
		start++;
	while (end > start && ft_chcmp(set, s1[end - 1]))
		end--;
	s1_trim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s1_trim)
		return (NULL);
	i = 0;
	while (start < end)
	{
		s1_trim[i] = s1[start];
		start++;
		i++;
	}
	s1_trim[i] = '\0';
	return (s1_trim);
}
