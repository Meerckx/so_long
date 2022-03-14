/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:52:27 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:35 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_specifier_error(const char *format, size_t i,
	t_flags *flags, size_t *length)
{
	if (!format[i + 1])
		return (i + 1);
	ft_putchar_fd(format[i], 1);
	i++;
	(*length)++;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (flags->type == '%')
			{
				ft_putchar_fd(format[i], 1);
				flags->type = 0;
			}
			else
				break ;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
		(*length)++;
	}
	return (i);
}
