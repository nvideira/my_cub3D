/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:29:17 by nvideira          #+#    #+#             */
/*   Updated: 2023/04/03 22:40:57 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_close(t_input *mlbx)
{
	mlx_destroy_window(mlbx->mlx, mlbx->window);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_input *mlbx)
{
	if (keycode == ESC_KEY)
		ft_close(mlbx);
	// else if (keycode == D_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y][mlbx->player.x + 1] != '1')
	// 	move_pl(mlbx, 0, 1);
	// else if (keycode == A_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y][mlbx->player.x - 1] != '1')
	// 	move_pl(mlbx, 0, -1);
	// else if (keycode == W_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y - 1][mlbx->player.x] != '1')
	// 	move_pl(mlbx, -1, 0);
	// else if (keycode == S_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y + 1][mlbx->player.x] != '1')
	// 	move_pl(mlbx, 1, 0);
	return (0);
}