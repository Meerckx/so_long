/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:04:06 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:42:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	last;

	if (!str)
		return (NULL);
	i = 0;
	last = -1;
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			last = i;
		i++;
	}
	if (str[i] == (char)ch)
		last = i;
	if (last == -1)
		return (NULL);
	else
		return ((char *)&str[last]);
}
