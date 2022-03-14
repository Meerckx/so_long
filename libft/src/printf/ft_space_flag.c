/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:26:38 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:33 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_space_flag(const char *format, size_t i, t_flags *flags)
{
	if (!flags->plus)
		flags->space = 1;
	while (format[i] == ' ')
		i++;
	return (i);
}
