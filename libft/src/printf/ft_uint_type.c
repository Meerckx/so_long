/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:05:51 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:43 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_precision_uint(t_list **list, t_flags *flags, size_t len)
{
	while ((int)len < flags->precision)
	{
		ft_lstadd_front(list, ft_lstnew("0"));
		len++;
	}
	return (len);
}

static size_t	ft_width_uint(t_list **list, t_flags *flags, size_t len)
{
	if ((flags->zero) && (flags->precision == -1) && (!flags->minus))
	{
		while ((int)len < flags->width)
		{
			ft_lstadd_front(list, ft_lstnew("0"));
			len++;
		}
	}
	while ((int)len < flags->width)
	{
		if (flags->minus)
			ft_lstadd_back(list, ft_lstnew(" "));
		else
			ft_lstadd_front(list, ft_lstnew(" "));
		len++;
	}
	return (len);
}

size_t	ft_uint_type(unsigned int num, t_flags *flags)
{
	char	*number;
	t_list	*list;
	size_t	len;

	list = NULL;
	len = 0;
	if (!num && flags->precision == 0)
		list = NULL;
	else
	{
		number = ft_itoa_uint(num);
		list = ft_lst_without_alloc(number);
		len = ft_strlen(number);
	}
	len = ft_precision_uint(&list, flags, len);
	len = ft_width_uint(&list, flags, len);
	ft_print_list(list);
	return (len);
}
