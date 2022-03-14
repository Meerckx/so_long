/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:16:23 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:58:38 by anonymous        ###   ########.fr       */
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
	else
		return (0);
	return (1);
}

int	input(int key, t_game *game)
{
	int	is_moved;

	is_moved = 0;
	if (!game->player.tile)
		return (0);
	if (key == ESC)
		exit_game(game);
	else if (key == W)
		is_moved = move(game, game->player.tile->up);
	else if (key == D)
		is_moved = move(game, game->player.tile->right);
	else if (key == S)
		is_moved = move(game, game->player.tile->down);
	else if (key == A)
		is_moved = move(game, game->player.tile->left);
	if (is_moved)
		ft_printf("Number of moves = %d\n", game->num_of_moves);
	render(game);
	return (1);
}
