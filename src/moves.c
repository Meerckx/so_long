/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:47:04 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:58:46 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
	game->num_of_moves++;
}

void	move_to_coin(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
	game->num_to_collect--;
	game->num_of_moves++;
	if (!game->num_to_collect)
		game->exit.tile->type = EXIT;
}

void	move_to_exit(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
	game->num_of_moves++;
	win_game(game);
}
