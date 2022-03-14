/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:02:59 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:16 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_star_precision(va_list ap, size_t i, t_flags *flags)
{
	flags->precision = va_arg(ap, int);
	return (i + 1);
}

size_t	ft_digit_precision(const char *format, size_t i, t_flags *flags)
{
	char	ch;

	flags->precision = 0;
	while (ft_isdigit(format[i]))
	{
		ch = format[i];
		flags->precision = flags->precision * 10 + (ch - '0');
		i++;
	}
	return (i);
}
