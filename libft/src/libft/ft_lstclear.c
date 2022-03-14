/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:45:47 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:41:18 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;

	if (!(*lst))
		return ;
	while (*lst)
	{
		current = (*lst);
		(*lst) = (*lst)->next;
		free(current->content);
		current->content = NULL;
		free(current);
		current = NULL;
	}
}
