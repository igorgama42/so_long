/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:32:14 by igama             #+#    #+#             */
/*   Updated: 2024/02/28 12:32:17 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_initializer(t_game *game)
{
	game->space = mlx_xpm_file_to_image
		(game->mlx, "textures/0.xpm", &game->img_w, &game->img_h);
	game->wall = mlx_xpm_file_to_image
		(game->mlx, "textures/1.xpm", &game->img_w, &game->img_h);
	game->player = mlx_xpm_file_to_image
		(game->mlx, "textures/KD.xpm", &game->img_w, &game->img_h);
	game->collect = mlx_xpm_file_to_image
		(game->mlx, "textures/C.xpm", &game->img_w, &game->img_h);
	game->exit = mlx_xpm_file_to_image
		(game->mlx, "textures/E1.xpm", &game->img_w, &game->img_h);
}

static void	size_window_initializer(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->map_h = i * 32;
}

void	game_initializer(t_game *game)
{
	game->mlx = mlx_init();
	size_window_initializer(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves = 0;
	game->endgame = 0;
	img_initializer(game);
	drawing_map(game);
}
