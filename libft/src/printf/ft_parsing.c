/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:55:03 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_arrays_init(t_flags *flags)
{
	ft_strlcpy(flags->types, "cspdiuxX%", 10);
	ft_strlcpy(flags->flag, "-0# +", 6);
}

static void	ft_flags_init(t_flags *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	flags->star = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->plus = 0;
	flags->error = 0;
	ft_arrays_init(flags);
}

size_t	ft_parsing(const char *format, va_list ap)
{
	t_flags	flags;
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_flags_init(&flags);
			i = ft_specifier_parsing(format, ap, i, &flags);
			if (flags.error)
				i = ft_specifier_error(format, i, &flags, &length);
			else
				length += ft_processor(ap, &flags);
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			length++;
		}
	}
	return (length);
}
