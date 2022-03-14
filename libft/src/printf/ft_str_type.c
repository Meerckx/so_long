/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:03:17 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:40 by anonymous        ###   ########.fr       */
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

static char	*ft_newstr(int precision, char *str)
{
	size_t	i;
	char	*newstr;

	if (!str)
		str = "(null)";
	newstr = (char *)malloc(sizeof(char) * (precision + 1));
	i = 0;
	while ((int)i < precision && str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

size_t	ft_str_type(char *str, t_flags *flags)
{
	t_list	*list;
	size_t	len;

	if (flags->precision > -1)
	{
		str = ft_newstr(flags->precision, str);
		list = ft_lst_without_alloc(str);
	}
	else
		list = ft_lstnew(str);
	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	len = ft_width_char(&list, flags, len);
	ft_print_list(list);
	return (len);
}
