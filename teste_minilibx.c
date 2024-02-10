/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_minilibx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:19:39 by igama             #+#    #+#             */
/*   Updated: 2024/02/08 10:41:39 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_linux/mlx.h"
#include "so_long.h"
#include <stdio.h>

int	key_hook(int keycode, t_vars *vars)
{
	static int	i;

	(void) vars;
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
	{
		printf ("Counter: %i\n", ++i);
		printf("Key Pressed: %c\n", keycode);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 720, 360, "First Screen");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
