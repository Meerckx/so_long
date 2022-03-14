/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:45:32 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 12:41:09 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_percent_type(t_flags *flags)
{
	t_list	*list;
	size_t	len;

	list = ft_lstnew("%");
	len = 1;
	while ((int)len < flags->width)
	{
		if (flags->minus)
			ft_lstadd_back(&list, ft_lstnew(" "));
		else if (flags->zero)
			ft_lstadd_front(&list, ft_lstnew("0"));
		else
			ft_lstadd_front(&list, ft_lstnew(" "));
		len++;
	}
	ft_print_list(list);
	return (len);
}
