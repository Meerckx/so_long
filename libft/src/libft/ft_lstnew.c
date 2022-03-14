/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:38:06 by tbaharat          #+#    #+#             */
/*   Updated: 2022/02/15 19:41:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;
	char	*new_content;

	new_content = ft_strdup(content);
	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->content = new_content;
		list->next = NULL;
	}
	return (list);
}

t_list	*ft_lst_without_alloc(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->content = content;
		list->next = NULL;
	}
	return (list);
}
