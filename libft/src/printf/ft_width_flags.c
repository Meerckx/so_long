/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:18:56 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:45 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_star_width(va_list ap, size_t i, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(ap, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->zero = 0;
		flags->width *= -1;
	}
	return (i + 1);
}

size_t	ft_digit_width(const char *format, size_t i, t_flags *flags)
{
	char	ch;

	while (ft_isdigit(format[i]))
	{
		ch = format[i];
		flags->width = flags->width * 10 + (ch - '0');
		i++;
	}
	return (i);
}
