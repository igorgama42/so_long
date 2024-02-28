/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:32:14 by igama             #+#    #+#             */
/*   Updated: 2024/02/28 14:59:46 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_movement(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
	{
		game->y_player -= 1;
		move_w(game);
	}
	else if (keycode == 97 || keycode == 65361)
	{
		game->x_player -= 1;
		move_a(game);
	}
	else if (keycode == 115 || keycode == 65364)
	{
		game->y_player += 1;
		move_s(game);
	}
	else if (keycode == 100 || keycode == 65363)
	{
		game->x_player += 1;
		move_d(game);
	}
}

static int	quiter(int keycode, t_game *game)
{
	if (keycode == 65307)
		game_closer(game);
	else if (!game->endgame)
	{
		player_movement(keycode, game);
		printf("Moves: %d\n", game->moves);
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, quiter, game);
	mlx_hook(game->win, 17, 1L << 17, game_closer, game);
	mlx_hook(game->win, 9, 1L << 21, drawing_map, game);
}
