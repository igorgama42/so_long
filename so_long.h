/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:10:48 by igama             #+#    #+#             */
/*   Updated: 2024/02/28 15:03:12 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libraries/minilibx/mlx.h"
# include "libraries/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*space;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
}			t_game;

void	game_initializer(t_game *game);
void	gameplay(t_game *game);
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	drawing_image(t_game *game, void *image, int x, int y);
int		drawing_map(t_game *game);
int		map_validator(t_game *game);
char	**map_maker(char *path);
void	free_map(char **map);
int		game_closer(t_game *game);

#endif
