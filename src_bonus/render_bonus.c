/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:17:27 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 16:47:15 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_image(t_game *game, t_tile tile)
{
	if (tile.type == PLAYER)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player.img, tile.position.x + 8, tile.position.y);
	else if (tile.type == RIVAL)
		mlx_put_image_to_window(game->mlx, game->window,
			game->rival.img, tile.position.x + 9, tile.position.y);
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

static void	draw_text(t_game *game)
{
	char	*str;

	str = ft_itoa(game->num_of_moves);
	mlx_string_put(game->mlx, game->window, game->window_size.x
		+ TILE_SIZE / 2.6, game->window_size.y / 2, -1, str);
	free(str);
}

static void	draw_frame(t_game *game)
{
	size_t	x;
	size_t	y;

	mlx_clear_window(game->mlx, game->window);
	usleep(50000);
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
	draw_text(game);
}

int	render(t_game *game)
{
	player_animation(&game->player);
	coin_animation(&game->coin);
	draw_frame(game);
	return (1);
}
