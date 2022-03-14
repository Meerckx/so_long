/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_tilemap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:59:56 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:58:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_tile	**alloc_tilemap(char **map, t_game *game)
{
	size_t	i;
	t_tile	**tilemap;

	tilemap = (t_tile **)malloc(sizeof(t_tile *) * game->checker.lines_count);
	if (!tilemap)
	{
		map_clear(map, game->checker.lines_count);
		end_game("Error\nTilemap memory allocation failed\n");
	}
	i = 0;
	while (i < game->checker.lines_count)
	{
		tilemap[i] = (t_tile *)malloc(sizeof(t_tile)
				* game->checker.line_length);
		if (!tilemap[i])
		{
			while (i > 0)
				free(tilemap[--i]);
			free(tilemap);
			map_clear(map, game->checker.lines_count);
			end_game("Error\nTilemap memory allocation failed\n");
		}
		i++;
	}
	return (tilemap);
}
