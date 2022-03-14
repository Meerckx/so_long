/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:16:23 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 17:03:03 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COIN)
		move_to_coin(game, tile);
	else if (tile->type == EXIT)
		move_to_exit(game);
	else if (tile->type == RIVAL)
		move_to_rival(game);
	else
		return (0);
	return (1);
}

int	input(int key, t_game *game)
{
	if (!game->player.tile)
		return (0);
	if (key == ESC)
		exit_game(game);
	else if (key == W)
		move(game, game->player.tile->up);
	else if (key == D)
		move(game, game->player.tile->right);
	else if (key == S)
		move(game, game->player.tile->down);
	else if (key == A)
		move(game, game->player.tile->left);
	return (1);
}
