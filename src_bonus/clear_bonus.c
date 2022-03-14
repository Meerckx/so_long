/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:52:40 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:59:09 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_clear(char **map, size_t lines_count)
{
	size_t	i;

	i = 0;
	while (i < lines_count)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	tilemap_clear(t_tile **tilemap, size_t lines_count)
{
	size_t	i;

	i = 0;
	while (i < lines_count)
	{
		free(tilemap[i]);
		tilemap[i] = NULL;
		i++;
	}
	free(tilemap);
	tilemap = NULL;
}
