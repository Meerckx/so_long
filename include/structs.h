/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:35:34 by anonymous         #+#    #+#             */
/*   Updated: 2022/02/22 23:46:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdlib.h>

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_mapValidator
{
	size_t	line_length;
	size_t	lines_count;
	int		start;
	int		exit;
	int		collectible;
}				t_mapValidator;

typedef enum e_tileType
{
	WALL = '1',
	EMPTY = '0',
	COIN = 'C',
	PLAYER = 'P',
	RIVAL = 'R',
	EXIT = 'E'
}				t_tileType;

typedef struct s_tile
{
	t_vector		position;
	t_tileType		type;
	struct s_tile	*up;
	struct s_tile	*right;
	struct s_tile	*down;
	struct s_tile	*left;
}				t_tile;

typedef struct s_player
{
	t_tile	*tile;
	void	*img;
	int		frames;
}				t_player;

typedef struct s_rival
{
	t_tile	*tile;
	void	*img;
}				t_rival;

typedef struct s_coin
{
	t_tile	*tile;
	void	*img1;
	void	*img2;
	void	*current_img;
	int		frames;
}				t_coin;

typedef struct s_exit
{
	t_tile	*tile;
	void	*img;
}				t_exit;

typedef struct s_wall
{
	t_tile	*tile;
	void	*img;
}				t_wall;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		window_size;
	t_mapValidator	checker;
	t_tile			**tilemap;
	t_player		player;
	t_rival			rival;
	t_coin			coin;
	t_exit			exit;
	t_wall			wall;
	int				num_to_collect;
	int				num_of_moves;
	t_vector		image_size;
}				t_game;

#endif