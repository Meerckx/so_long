/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:35:38 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:41:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	**ft_words_memory(char const *s, size_t *words, char c)
{
	size_t	i;
	char	**strs;

	if (s == NULL)
		return (NULL);
	i = 0;
	*words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			(*words)++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	strs = (char **)malloc(sizeof(char *) * (*words + 1));
	if (!strs)
		return (NULL);
	return (strs);
}

static char	*ft_letters_memory(const char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_memfree(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	words;
	size_t	n;

	strs = ft_words_memory(s, &words, c);
	if (!strs)
		return (NULL);
	n = 0;
	while (n < words)
	{
		while (*s && *s == c)
			s++;
		strs[n] = ft_letters_memory(s, c);
		if (!strs[n])
		{
			ft_memfree(strs, n);
			free(strs);
			return (NULL);
		}
		n++;
		while (*s && *s != c)
			s++;
	}
	strs[n] = NULL;
	return (strs);
}
