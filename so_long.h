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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	keyhook(int keycode, t_vars *vars);

#endif
