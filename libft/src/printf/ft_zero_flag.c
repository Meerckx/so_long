/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:44:55 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:48 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_zero_flag(const char *format, size_t i, t_flags *flags)
{
	if (!flags->minus)
		flags->zero = 1;
	while (format[i] == '0')
		i++;
	return (i);
}
