/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_design.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:32:14 by igama             #+#    #+#             */
/*   Updated: 2024/02/28 16:33:03 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawing_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 32, y * 32);
}

static void	drawing_player(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	drawing_image(game, image, x, y);
}

static void	drawing_exit(t_game *game, int x, int y)
{
	if (game->n_collect == 0)
	{
		mlx_destroy_image(game->mlx, game->exit);
		game->exit = mlx_xpm_file_to_image
			(game->mlx, "textures/E2.xpm", &game->img_w, &game->img_h);
	}
	drawing_image(game, game->exit, x, y);
}

int	drawing_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				drawing_image(game, game->wall, x, y);
			else if (game->map[y][x] == '0')
				drawing_image(game, game->space, x, y);
			else if (game->map[y][x] == 'P')
				drawing_player(game, game->player, x, y);
			else if (game->map[y][x] == 'C')
				drawing_image(game, game->collect, x, y);
			else if (game->map[y][x] == 'E')
				drawing_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
