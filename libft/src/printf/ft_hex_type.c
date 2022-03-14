/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:28:16 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:40:56 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_width_hex(t_list **list, t_flags *flags, size_t len,
	unsigned int num)
{
	if ((flags->zero) && (flags->precision == -1) && (!flags->minus))
	{
		while ((int)len < flags->width - (flags->sharp * 2))
		{
			ft_lstadd_front(list, ft_lstnew("0"));
			len++;
		}
	}
	if (flags->sharp && num)
	{
		if (flags->type == 'x')
			ft_lstadd_front(list, ft_lstnew("0x"));
		else if (flags->type == 'X')
			ft_lstadd_front(list, ft_lstnew("0X"));
		len += 2;
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

static size_t	ft_number_len(unsigned int num)
{
	size_t	count;

	if (!num)
		return (1);
	count = 0;
	while (num)
	{
		count++;
		num /= 16;
	}
	return (count);
}

static char	*ft_hex_convert(unsigned int num, t_flags *flags)
{
	char	*number;
	size_t	len;
	t_hex	hex;

	ft_hex_init(&hex);
	len = ft_number_len(num);
	number = (char *)malloc(sizeof(char) * (len + 1));
	number[len] = '\0';
	len--;
	while (len)
	{
		if (flags->type == 'x')
			number[len] = hex.lowercase[num % 16];
		else if (flags->type == 'X')
			number[len] = hex.uppercase[num % 16];
		len--;
		num /= 16;
	}
	if (flags->type == 'x')
		number[len] = hex.lowercase[num % 16];
	else if (flags->type == 'X')
		number[len] = hex.uppercase[num % 16];
	return (number);
}

size_t	ft_hex_type(unsigned int num, t_flags *flags)
{
	t_list	*list;
	size_t	len;
	char	*number;

	len = 0;
	if (!num && flags->precision == 0)
		list = NULL;
	else
	{
		number = ft_hex_convert(num, flags);
		list = ft_lst_without_alloc(number);
		len = ft_strlen(number);
	}
	while ((int)len < flags->precision)
	{
		ft_lstadd_front(&list, ft_lstnew("0"));
		len++;
	}
	len = ft_width_hex(&list, flags, len, num);
	ft_print_list(list);
	return (len);
}
