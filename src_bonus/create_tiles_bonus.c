/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tiles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:27:29 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:59:11 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_tileType	get_tiletype(char ch)
{
	if (ch == '0')
		return (EMPTY);
	else if (ch == '1')
		return (WALL);
	else if (ch == 'P')
		return (PLAYER);
	else if (ch == 'R')
		return (RIVAL);
	else if (ch == 'E')
		return (EXIT);
	else if (ch == 'C')
		return (COIN);
	else
		return (0);
}

static void	set_neighbours(t_tile **tilemap, size_t x,
	size_t y, t_mapValidator checker)
{
	tilemap[y][x].up = NULL;
	tilemap[y][x].right = NULL;
	tilemap[y][x].down = NULL;
	tilemap[y][x].left = NULL;
	tilemap[y][x].position.x = x * TILE_SIZE;
	tilemap[y][x].position.y = y * TILE_SIZE;
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	if (x != checker.line_length - 1)
		tilemap[y][x].right = &tilemap[y][x + 1];
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (y != checker.lines_count - 1)
		tilemap[y][x].down = &tilemap[y + 1][x];
}

static void	set_components(t_tile *tile, t_game *game)
{
	if (tile->type == PLAYER)
		game->player.tile = tile;
	else if (tile->type == RIVAL)
		game->rival.tile = tile;
	else if (tile->type == COIN)
	{
		game->num_to_collect++;
		game->coin.tile = tile;
	}
	else if (tile->type == EXIT)
	{
		game->exit.tile = tile;
		game->exit.tile->type = EMPTY;
	}
	else if (tile->type == WALL)
		game->wall.tile = tile;
}

static void	tilemap_init(char **map, t_tile **tilemap, t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->checker.lines_count)
	{
		x = 0;
		while (x < game->checker.line_length)
		{
			tilemap[y][x].type = get_tiletype(map[y][x]);
			set_neighbours(tilemap, x, y, game->checker);
			set_components(&tilemap[y][x], game);
			x++;
		}
		y++;
	}
	game->window_size.x = game->checker.line_length * TILE_SIZE;
	game->window_size.y = game->checker.lines_count * TILE_SIZE;
}

t_tile	**create_tiles(char **map, t_game *game)
{
	t_tile	**tilemap;

	tilemap = alloc_tilemap(map, game);
	tilemap_init(map, tilemap, game);
	map_clear(map, game->checker.lines_count);
	return (tilemap);
}
