/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:09:30 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:42:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)str1;
	us2 = (unsigned char *)str2;
	i = 0;
	while (i < n && (us1[i] || us2[i]))
	{
		if (us1[i] > us2[i])
			return (1);
		if (us1[i] < us2[i])
			return (-1);
		i++;
	}
	return (0);
}
