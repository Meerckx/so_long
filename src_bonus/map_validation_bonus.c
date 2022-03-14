/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:08:50 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:59:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	lines_valid(char *map, t_game *game, size_t i)
{
	size_t	j;

	if (i == 0 || i == game->checker.lines_count - 1)
	{
		j = 0;
		while (j < game->checker.line_length)
		{
			if (map[j] != '1')
				return (0);
			j++;
		}
	}
	else
	{
		if (map[0] != '1' || map[game->checker.line_length - 1] != '1')
			return (0);
	}
	return (1);
}

static int	surroundings_valid(char **map, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->checker.lines_count)
	{
		if (ft_strlen(map[i]) != game->checker.line_length)
			return (0);
		if (!lines_valid(map[i], game, i))
			return (0);
		i++;
	}
	return (1);
}

static int	characters_valid(char **map, t_game *game)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < game->checker.lines_count - 1)
	{
		j = 1;
		while (j < game->checker.line_length - 1)
		{
			if (map[i][j] == 'C')
				game->checker.collectible = 1;
			else if (map[i][j] == 'E')
				game->checker.exit++;
			else if (map[i][j] == 'P')
				game->checker.start++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'R')
				return (0);
			j++;
		}
		i++;
	}
	if (game->checker.collectible != 1 || game->checker.exit != 1
		|| game->checker.start != 1)
		return (0);
	return (1);
}

int	map_validation(char **map, t_game *game)
{
	game->checker.line_length = ft_strlen(map[0]);
	if (game->checker.lines_count <= 2 || game->checker.line_length <= 2)
		return (0);
	if (!surroundings_valid(map, game))
		return (0);
	if (!characters_valid(map, game))
		return (0);
	return (1);
}
