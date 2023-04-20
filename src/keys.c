/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:29:17 by nvideira          #+#    #+#             */
/*   Updated: 2023/04/20 17:23:44 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_close(t_input *mlbx)
{
	mlx_destroy_window(mlbx->mlx, mlbx->window);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_input *in)
{
	if (keycode == ESC_KEY)
		ft_close(in);
	// else if (keycode == D_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y][mlbx->player.x + 1] != '1')
	// 	move_pl(mlbx, 0, 1);
	// else if (keycode == A_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y][mlbx->player.x - 1] != '1')
	// 	move_pl(mlbx, 0, -1);
	else if (keycode == W_KEY)
		move_fwd(in);
	// else if (keycode == S_KEY
	// 	&& mlbx->map.matrix[mlbx->player.y + 1][mlbx->player.x] != '1')
	// 	move_pl(mlbx, 1, 0);
	else if (keycode == LEFT_KEY)
		rotate(in, 1);
	else if (keycode == RIGHT_KEY)
		rotate(in, -1);
	return (0);
}

void	rotate(t_input *in, int dir)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = in->play->dir_x;
	in->play->dir_x = in->play->dir_x * cos(dir * in->chrono->rot_speed) - in->play->dir_y * sin(dir * in->chrono->rot_speed);
	in->play->dir_y = old_dir_x * sin(dir * in->chrono->rot_speed) + in->play->dir_y * cos(dir * in->chrono->rot_speed);
	old_plane_x = in->play->plane_x;
	in->play->plane_x = in->play->plane_x * cos(dir * in->chrono->rot_speed) - in->play->plane_y * sin(dir * in->chrono->rot_speed);
	in->play->plane_y = old_plane_x * sin(dir * in->chrono->rot_speed) + in->play->plane_y * cos(dir * in->chrono->rot_speed);
}

void	move_fwd(t_input *in)
{
	if(in->map[(int)(in->play->pos_x + in->play->dir_x * in->chrono->move_speed)][(int)(in->play->pos_y)] == 0)
		in->play->pos_x += in->play->dir_x * in->chrono->move_speed;
	if(in->map[(int)(in->play->pos_x)][(int)(in->play->pos_y + in->play->dir_y * in->chrono->move_speed)] == 0)
		in->play->pos_y += in->play->dir_y * in->chrono->move_speed;
}
