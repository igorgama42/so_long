/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:10:48 by igama             #+#    #+#             */
/*   Updated: 2024/02/08 11:11:35 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_map
{
	int	size;
}		t_map;

typedef struct s_data
{
	void	*mlx_ptr; // MLX POINTER
	void	*win_ptr; // MLX WINDOW POINTER
	void	*textures[5]; // MLX IMAGE POINTERS (ON THE STACK)
	t_map	*map; // MAP POINTER (CONTAINS MAP DETAILS - PREFERABLY KEPT ON THE STACK)
}		t_data;

int	keyhook(int keycode, t_data *vars);

#endif
