/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:31:55 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_minus_flag(const char *format, size_t i, t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
	while (format[i] == '-')
		i++;
	return (i);
}
