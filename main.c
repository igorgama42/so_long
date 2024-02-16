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

int	key_hook(int keycode, t_data *vars)
{
	static int	i;

	(void) vars;
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
	{
		printf ("Counter: %i\n", ++i);
		printf("Key Pressed: %c\n", keycode);
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		//mlx_destroy_display(vars->mlx_ptr);
		mlx_loop_end(vars->mlx_ptr);
	}
	return (0);
}

int	main(void)
{
	t_data	vars;

	vars.mlx_ptr = mlx_init();
	if (!vars.mlx_ptr)
		return (1);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 720, 360, "First Screen");
	if (!vars.win_ptr)
		return (free(vars.mlx_ptr), 1);
	mlx_key_hook(vars.win_ptr, key_hook, &vars);
	mlx_loop(vars.mlx_ptr);
	free(vars.mlx_ptr);
	return (0);
}
