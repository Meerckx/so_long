/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:30:06 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_processor(va_list ap, t_flags *flags)
{
	size_t	length;

	length = 0;
	if (flags->type == '%')
		length = ft_percent_type(flags);
	else if (flags->type == 'c')
		length = ft_char_type(va_arg(ap, int), flags);
	else if (flags->type == 's')
		length = ft_str_type(va_arg(ap, char *), flags);
	else if (flags->type == 'p')
		length = ft_pointer_type((unsigned long)va_arg(ap, void *), flags);
	else if (flags->type == 'i' || flags->type == 'd')
		length = ft_intdec_type(va_arg(ap, int), flags);
	else if (flags->type == 'u')
		length = ft_uint_type(va_arg(ap, unsigned int), flags);
	else if (flags->type == 'x' || flags->type == 'X')
		length = ft_hex_type (va_arg(ap, unsigned int), flags);
	return (length);
}
