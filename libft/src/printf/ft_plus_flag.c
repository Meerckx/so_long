/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:34:56 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:12 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_plus_flag(const char *format, size_t i, t_flags *flags)
{
	flags->plus = 1;
	flags->space = 0;
	while (format[i] == '+')
		i++;
	return (i);
}
