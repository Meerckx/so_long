/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:55:21 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 18:00:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_print_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		if (current->content)
			ft_putstr_fd(current->content, 1);
		else
			write(1, "(null)", 6);
		current = current->next;
	}
	ft_lstclear(&list);
}

void	ft_print_list_char(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		ft_putchar_fd(((char *)(current->content))[0], 1);
		current = current->next;
	}
	ft_lstclear(&list);
}
