/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:05:17 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 14:16:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*remstr(char *str, char *remnant)
{
	char	*new_str;
	size_t	i;
	size_t	i_tmp;

	new_str = (char *)malloc(sizeof(char)
			* (ft_strlen(str) + ft_strlen(remnant) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	i_tmp = 0;
	if (remnant)
	{
		while (remnant[i_tmp])
			new_str[i++] = remnant[i_tmp++];
	}
	i_tmp = 0;
	while (str[i_tmp])
		new_str[i++] = str[i_tmp++];
	new_str[i] = '\0';
	free(remnant);
	return (new_str);
}

char	*remtrim(char *remnant)
{
	char	*new_str;
	size_t	i;
	size_t	i_tmp;

	i_tmp = 0;
	i = 0;
	while (remnant[i_tmp] != '\n')
		i_tmp++;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(remnant) - i_tmp));
	i_tmp++;
	while (remnant[i_tmp])
	{
		new_str[i] = remnant[i_tmp];
		i++;
		i_tmp++;
	}
	new_str[i] = '\0';
	free(remnant);
	return (new_str);
}

int	is_newline(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
