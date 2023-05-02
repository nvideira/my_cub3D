/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:29:17 by nvideira          #+#    #+#             */
/*   Updated: 2023/05/02 15:16:51 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_close(void)
{
	mlx_destroy_window(vars()->mlx, vars()->window);
	exit(0);
	return (0);
}

int	key_press(int keycode)
{
	if (keycode == ESC_KEY)
		ft_close();
	else if (keycode == D_KEY)
		move_rsw();
	else if (keycode == A_KEY)
		move_lsw();
	else if (keycode == W_KEY)
		move_fwd();
	else if (keycode == S_KEY)
		move_bwd();
	else if (keycode == LEFT_KEY)
		rotate(1);
	else if (keycode == RIGHT_KEY)
		rotate(-1);
	raycast_main();
	return (0);
}

void	rotate(int dir)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars()->play->dir_x;
	vars()->play->dir_x = vars()->play->dir_x \
		* cos(dir * vars()->chrono->rot_speed) - vars()->play->dir_y \
		* sin(dir * vars()->chrono->rot_speed);
	vars()->play->dir_y = old_dir_x * sin(dir * vars()->chrono->rot_speed) \
		+ vars()->play->dir_y * cos(dir * vars()->chrono->rot_speed);
	old_plane_x = vars()->play->plane_x;
	vars()->play->plane_x = vars()->play->plane_x \
		* cos(dir * vars()->chrono->rot_speed) - vars()->play->plane_y \
		* sin(dir * vars()->chrono->rot_speed);
	vars()->play->plane_y = old_plane_x * sin(dir * vars()->chrono->rot_speed) \
		+ vars()->play->plane_y * cos(dir * vars()->chrono->rot_speed);
}

void	fps_count(void)
{
	vars()->chrono->old_time = vars()->chrono->time;
	vars()->chrono->time = clock();
	vars()->chrono->frame_time = (double)(vars()->chrono->time \
		- vars()->chrono->old_time) / CLOCKS_PER_SEC;
	vars()->chrono->move_speed = vars()->chrono->frame_time * 5000.0;
	vars()->chrono->rot_speed = vars()->chrono->frame_time * 3000.0;
}
