/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:48:47 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 17:00:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_animation(t_player *player)
{
	if (player->frames < 4)
		player->tile->position.x += 1;
	else if (player->frames < 8)
		player->tile->position.x -= 1;
	player->frames++;
	if (player->frames == 8)
		player->frames = 0;
}

void	coin_animation(t_coin *coin)
{
	if (coin->frames == 8)
		coin->current_img = coin->img2;
	else if (coin->frames == 15)
	{
		coin->current_img = coin->img1;
		coin->frames = 0;
	}
	coin->frames++;
}
