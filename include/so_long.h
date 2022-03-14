/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:30:34 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/06 16:01:13 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64
# define W 119
# define D 100
# define S 115
# define A 97
# define ESC 65307
# include <fcntl.h>
# include "structs.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

t_tile	**map_init(char *file, t_game *game);
t_tile	**create_tiles(char **map, t_game *game);
t_tile	**alloc_tilemap(char **map, t_game *game);
char	**map_read(char	*file, t_game *game);
void	start_game(char *file, t_game *game);
void	end_game(char *str);
void	map_clear(char	**map, size_t lines_count);
void	tilemap_clear(t_tile **tilemap, size_t lines_count);
void	move_to_rival(t_game *game);
void	move_to_coin(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	player_animation(t_player *player);
void	coin_animation(t_coin *coin);
int		input(int key, t_game *game);
int		render(t_game *game);
int		map_validation(char **map, t_game *game);
int		exit_game(t_game *game);
int		win_game(t_game *game);
int		lose_game(t_game *game);

#endif