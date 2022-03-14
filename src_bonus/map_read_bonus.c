/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:29:00 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 15:59:22 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	rows_count(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		end_game("Error\nCan not open file\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
			game->checker.lines_count++;
		free(line);
	}
	close(fd);
}

static void	assign_lines(char **map, int fd, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->checker.lines_count)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			end_game("Error\nMap memory allocation failed\n");
		}
		i++;
	}
}

char	**map_read(char	*file, t_game *game)
{
	int		fd;
	char	**map;

	rows_count(file, game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		end_game("Error\nCan not open file\n");
	map = (char **)malloc(game->checker.lines_count * sizeof(char *));
	if (!map)
		end_game("Error\nMap memory allocation failed\n");
	assign_lines(map, fd, game);
	close(fd);
	return (map);
}
