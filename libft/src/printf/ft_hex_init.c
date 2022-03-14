/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:18:54 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:40:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_hex_init(t_hex *hex)
{
	size_t	i;
	int		ch;

	i = 0;
	while (i < 10)
	{
		hex->uppercase[i] = i + '0';
		hex->lowercase[i] = i + '0';
		i++;
	}
	ch = 'a';
	while (i < 16)
	{
		hex->uppercase[i] = ch - 32;
		hex->lowercase[i] = ch;
		ch++;
		i++;
	}
	hex->lowercase[i] = '\0';
	hex->uppercase[i] = '\0';
}
