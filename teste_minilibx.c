/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:19:39 by igama             #+#    #+#             */
/*   Updated: 2024/02/02 11:09:26 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_linux/mlx.h"
#include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("%c\n",keycode);
	return (0);
}

int	main(void)
{	
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 720, 360, "Hello World!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
