/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:02:42 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_sharp_flag(const char *format, size_t i, t_flags *flags)
{
	flags->sharp = 1;
	while (format[i] == '#')
		i++;
	return (i);
}
