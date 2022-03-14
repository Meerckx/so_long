/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:16:34 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:59:19 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	checker_init(t_mapValidator *checker)
{
	checker->lines_count = 0;
	checker->line_length = 0;
	checker->collectible = 0;
	checker->start = 0;
	checker->exit = 0;
}

static int	is_ber_end(char *file)
{
	size_t			i;
	size_t			len;
	unsigned char	ber[5];

	ber[0] = '.';
	ber[1] = 'b';
	ber[2] = 'e';
	ber[3] = 'r';
	ber[4] = '\0';
	i = 0;
	len = ft_strlen(file);
	while (i < 4)
	{
		if (file[len - i - 1] != ber[4 - i - 1])
			return (0);
		i++;
	}
	return (1);
}

t_tile	**map_init(char *file, t_game *game)
{
	t_tile	**tilemap;
	char	**map;

	checker_init(&game->checker);
	if (!is_ber_end(file))
		end_game("Error\nOnly .ber files are valid\n");
	map = map_read(file, game);
	if (!map_validation(map, game))
	{
		map_clear(map, game->checker.lines_count);
		end_game("Error\nInvalid map\n");
	}
	tilemap = create_tiles(map, game);
	return (tilemap);
}
