/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:17:27 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 17:01:14 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_image(t_game *game, t_tile tile)
{
	if (tile.type == PLAYER)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player.img, tile.position.x + 8, tile.position.y);
	else if (tile.type == WALL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall.img, tile.position.x + 8, tile.position.y);
	else if (tile.type == COIN)
		mlx_put_image_to_window(game->mlx, game->window,
			game->coin.current_img, tile.position.x + 11, tile.position.y + 11);
	else if (tile.type == EXIT && game->num_to_collect == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit.img, tile.position.x + 9, tile.position.y);
}

static void	draw_frame(t_game *game)
{
	size_t	x;
	size_t	y;

	mlx_clear_window(game->mlx, game->window);
	y = 0;
	while (y < game->checker.lines_count)
	{
		x = 0;
		while (x < game->checker.line_length)
		{
			draw_image(game, (game->tilemap)[y][x]);
			x++;
		}
		y++;
	}
}

int	render(t_game *game)
{
	draw_frame(game);
	return (1);
}
