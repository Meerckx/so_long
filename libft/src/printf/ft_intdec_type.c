/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdec_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:04:18 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:40:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_precision_int(t_list **list, t_flags *flags, size_t len)
{
	while ((int)len < flags->precision)
	{
		ft_lstadd_front(list, ft_lstnew("0"));
		len++;
	}
	return (len);
}

static int	ft_space_plus(t_list **list, t_flags *flags, size_t *len, int num)
{
	if (flags->plus)
	{
		if (num >= 0)
			ft_lstadd_front(list, ft_lstnew("+"));
		else
			ft_lstadd_front(list, ft_lstnew("-"));
		(*len)++;
		flags->space = 0;
	}
	else if (num < 0)
	{
		ft_lstadd_front(list, ft_lstnew("-"));
		(*len)++;
		flags->space = 0;
	}
	else if (flags->space)
		return (1);
	return (0);
}

static size_t	ft_width_int(t_list **list, t_flags *flags, size_t len, int num)
{
	int	flag;

	flag = 0;
	if (flags->space || flags->plus || num < 0)
		flag = 1;
	if ((flags->zero) && (flags->precision == -1) && (!flags->minus))
	{
		while ((int)len < (flags->width - flag))
		{
			ft_lstadd_front(list, ft_lstnew("0"));
			len++;
		}
	}
	flag = ft_space_plus(list, flags, &len, num);
	while ((int)len < (flags->width - flag))
	{
		if (flags->minus)
			ft_lstadd_back(list, ft_lstnew(" "));
		else
			ft_lstadd_front(list, ft_lstnew(" "));
		len++;
	}
	return (len);
}

size_t	ft_intdec_type(int num, t_flags *flags)
{
	char	*number;
	t_list	*list;
	size_t	len;

	len = 0;
	number = NULL;
	if (!num && flags->precision == 0)
		list = NULL;
	else
	{
		number = ft_printf_itoa(num);
		list = ft_lst_without_alloc(number);
		len = ft_strlen(number);
	}
	len = ft_precision_int(&list, flags, len);
	len = ft_width_int(&list, flags, len, num);
	if (flags->space)
	{
		ft_lstadd_front(&list, ft_lstnew(" "));
		len++;
	}
	ft_print_list(list);
	return (len);
}
