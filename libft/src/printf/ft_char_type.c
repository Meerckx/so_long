/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:09:22 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:40:48 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_width_char(t_list **list, t_flags *flags, size_t len)
{
	while ((int)len < flags->width)
	{
		if (flags->minus)
			ft_lstadd_back(list, ft_lstnew(" "));
		else if (flags->zero)
			ft_lstadd_front(list, ft_lstnew("0"));
		else
			ft_lstadd_front(list, ft_lstnew(" "));
		len++;
	}
	return (len);
}

size_t	ft_char_type(int ch, t_flags *flags)
{
	t_list	*list;
	size_t	len;
	char	str[2];

	str[0] = (unsigned char)ch;
	str[1] = '\0';
	list = ft_lstnew(str);
	len = 1;
	len = ft_width_char(&list, flags, len);
	ft_print_list_char(list);
	return (len);
}
