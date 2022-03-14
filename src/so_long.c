/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:30:07 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:58:50 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		end_game("Error\nOnly one argument is needed after ./so_long\n");
	start_game(argv[1], &game);
	mlx_hook(game.window, 2, 1L << 0, input, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
