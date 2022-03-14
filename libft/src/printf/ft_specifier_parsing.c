/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:00:26 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:38 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_flags_parsing(const char *format, size_t i, t_flags *flags)
{
	while (ft_isflag(format[i], flags))
	{
		if (format[i] == ' ')
			i = ft_space_flag(format, i, flags);
		if (format[i] == '0')
			i = ft_zero_flag(format, i, flags);
		if (format[i] == '-')
			i = ft_minus_flag(format, i, flags);
		if (format[i] == '+')
			i = ft_plus_flag(format, i, flags);
		if (format[i] == '#')
			i = ft_sharp_flag(format, i, flags);
	}
	return (i);
}

static size_t	ft_width_parsing(const char *format, va_list ap,
	size_t i, t_flags *flags)
{
	if (format[i] == '*')
		i = ft_star_width(ap, i, flags);
	else if (ft_isdigit(format[i]))
		i = ft_digit_width(format, i, flags);
	return (i);
}

static size_t	ft_precision_parsing(const char *format, va_list ap,
	size_t i, t_flags *flags)
{
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
			i = ft_star_precision(ap, i, flags);
		else
			i = ft_digit_precision(format, i, flags);
		if (!ft_istypes(format[i], flags))
			flags->error = 1;
	}
	return (i);
}

static size_t	ft_type_parsing(const char *format, size_t i, t_flags *flags)
{
	if (ft_istypes(format[i], flags))
		flags->type = format[i];
	else
		flags->error = 1;
	return (i + 1);
}

size_t	ft_specifier_parsing(const char *format, va_list ap,
	size_t i, t_flags *flags)
{
	size_t	start_i;

	start_i = i;
	i++;
	i = ft_flags_parsing(format, i, flags);
	i = ft_width_parsing(format, ap, i, flags);
	i = ft_precision_parsing(format, ap, i, flags);
	i = ft_type_parsing(format, i, flags);
	if (flags->error)
		return (start_i);
	else
		return (i);
}
