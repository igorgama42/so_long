/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:19:39 by igama             #+#    #+#             */
/*   Updated: 2024/02/06 20:18:28 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_linux/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 360, "My game");
	img.img = mlx_new_image(mlx, 720, 360);
	mlx_string_put(mlx, mlx_win, 5, 25, 0x00ff0000, "Testando");
	mlx_loop(mlx);
}
