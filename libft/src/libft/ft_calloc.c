/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:43:56 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:40:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	i;

	arr = malloc(size * count);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)arr)[i] = '\0';
		i++;
	}
	return (arr);
}
