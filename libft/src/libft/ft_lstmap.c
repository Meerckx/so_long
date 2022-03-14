/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:29:24 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:41:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = ft_lst_without_alloc(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_list);
			free(new_list);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
