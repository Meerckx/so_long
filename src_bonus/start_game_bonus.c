/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:07:52 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:59:33 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->window_size.x + TILE_SIZE,
			game->window_size.y, "So_long");
	mlx_hook(game->window, 17, 1L << 17, exit_game, game);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"images/pickle_player.xpm",
			&game->image_size.x, &game->image_size.y);
	game->rival.img = mlx_xpm_file_to_image(game->mlx,
			"images/rick_rival.xpm", &game->image_size.x, &game->image_size.y);
	game->coin.img1 = mlx_xpm_file_to_image(game->mlx,
			"images/sun_coin.xpm", &game->image_size.x, &game->image_size.y);
	game->coin.img2 = mlx_xpm_file_to_image(game->mlx,
			"images/sun2_coin.xpm", &game->image_size.x, &game->image_size.y);
	game->coin.current_img = game->coin.img1;
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"images/portal_exit.xpm", &game->image_size.x, &game->image_size.y);
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"images/head_wall.xpm", &game->image_size.x, &game->image_size.y);
}

void	start_game(char *file, t_game *game)
{
	game->num_to_collect = 0;
	game->num_of_moves = 0;
	game->player.frames = 0;
	game->coin.frames = 0;
	game->tilemap = map_init(file, game);
	game_init(game);
}
