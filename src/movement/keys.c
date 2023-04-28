/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:29:17 by nvideira          #+#    #+#             */
/*   Updated: 2023/04/28 16:35:07 by ubuntu           ###   ########.fr       */
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
	// else if (keycode == D_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y][mlbx->player.x + 1] != '1')
	// 	move_pl(mlbx, 0, 1);
	// else if (keycode == A_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y][mlbx->player.x - 1] != '1')
	// 	move_pl(mlbx, 0, -1);
	else if (keycode == W_KEY)
		move_fwd();
	// else if (keycode == S_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y + 1][mlbx->player.x] != '1')
	// 	move_pl(mlbx, 1, 0);
	else if (keycode == LEFT_KEY)
		rotate(1);
	else if (keycode == RIGHT_KEY)
		rotate(-1);
	return (0);
}

void	rotate(int dir)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = vars()->play->dir_x;
	vars()->play->dir_x = vars()->play->dir_x * cos(dir * vars()->chrono->rot_speed) - vars()->play->dir_y * sin(dir * vars()->chrono->rot_speed);
	vars()->play->dir_y = old_dir_x * sin(dir * vars()->chrono->rot_speed) + vars()->play->dir_y * cos(dir * vars()->chrono->rot_speed);
	old_plane_x = vars()->play->plane_x;
	vars()->play->plane_x = vars()->play->plane_x * cos(dir * vars()->chrono->rot_speed) - vars()->play->plane_y * sin(dir * vars()->chrono->rot_speed);
	vars()->play->plane_y = old_plane_x * sin(dir * vars()->chrono->rot_speed) + vars()->play->plane_y * cos(dir * vars()->chrono->rot_speed);
}

void	move_fwd(void)
{
	printf("pos_x: %f\n", vars()->play->pos_x);
	printf("pos_y: %f\n", vars()->play->pos_y);
	if(vars()->map[(int)floor((vars()->play->pos_y))][(int)floor((vars()->play->pos_x + vars()->play->dir_x * vars()->chrono->move_speed))] == '0')
		vars()->play->pos_x += vars()->play->dir_x * vars()->chrono->move_speed;
	if(vars()->map[(int)(vars()->play->pos_y + vars()->play->dir_y * vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
		vars()->play->pos_y += vars()->play->dir_y * vars()->chrono->move_speed;
}

void	fps_count(void)
{
	vars()->chrono->old_time = vars()->chrono->time;
	vars()->chrono->time = clock();
	vars()->chrono->frame_time = (double)(vars()->chrono->time - vars()->chrono->old_time) / CLOCKS_PER_SEC;
	vars()->chrono->move_speed = vars()->chrono->frame_time * 5000.0;
	vars()->chrono->rot_speed = vars()->chrono->frame_time * 3.0;
}
