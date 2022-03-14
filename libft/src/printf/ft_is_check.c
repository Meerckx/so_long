/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:51:26 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_isflag(char ch, t_flags *flags)
{
	int	tmp_i;

	tmp_i = 0;
	while (flags->flag[tmp_i])
	{
		if (flags->flag[tmp_i] == ch)
			return (1);
		tmp_i++;
	}
	return (0);
}

int	ft_istypes(char ch, t_flags *flags)
{
	int	tmp_i;

	tmp_i = 0;
	while (flags->types[tmp_i])
	{
		if (flags->types[tmp_i] == ch)
			return (1);
		tmp_i++;
	}
	return (0);
}
