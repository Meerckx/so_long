/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:08:17 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:59:15 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_memory(t_game *game)
{
	tilemap_clear(game->tilemap, game->checker.lines_count);
	mlx_destroy_image(game->mlx, game->player.img);
	mlx_destroy_image(game->mlx, game->coin.img1);
	mlx_destroy_image(game->mlx, game->coin.img2);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->rival.img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	end_game(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

int	exit_game(t_game *game)
{
	ft_printf("Your session is over, come back again :)\n");
	free_memory(game);
	exit(0);
}

int	win_game(t_game *game)
{
	ft_printf("YOU WON! CONGRATULATIONS!\n");
	free_memory(game);
	exit(0);
}

int	lose_game(t_game *game)
{
	ft_printf("YOU LOSE! TRY AGAIN :C\n");
	free_memory(game);
	exit(0);
}
