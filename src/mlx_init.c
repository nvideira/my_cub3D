/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:35:32 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/20 15:35:24 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	define_dir_values(t_input *in)
{
	if (in->st_dir == 'N')
	{
		in->play->dir_x = 0;
		in->play->dir_y = -1;
		in->play->plane_x = -0.66;
		in->play->plane_y = 0;
	}
	else if (in->st_dir == 'S')
	{
		in->play->dir_x = 0;
		in->play->dir_y = 1;
		in->play->plane_x = 0.66;
		in->play->plane_y = 0;
	}
	else if (in->st_dir == 'E')
	{
		in->play->dir_x = 1;
		in->play->dir_y = 0;
		in->play->plane_x = 0;
		in->play->plane_y = 0.66;
	}
	else if (in->st_dir == 'W')
	{
		in->play->dir_x = -1;
		in->play->dir_y = 0;
		in->play->plane_x = 0;
		in->play->plane_y = -0.66;
	}
}

void	init_vars(t_input *in)
{
	in->play = (t_player *)malloc(sizeof(t_player));
 	find_player(in);
	define_dir_values(in);
 	in->play->cam_x = 0;
 	in->play->ray_d_x = 0;
 	in->play->ray_d_y = 0;
 	in->play->side_dist_x = 0;
 	in->play->side_dist_y = 0;
 	in->play->d_dist_x = 0;
 	in->play->d_dist_y = 0;
 	in->play->step_x = 0;
 	in->play->step_y = 0;
 	in->play->perp_wall_dist = 0;
 	in->play->hit = 0;
 	in->play->side = 0;
 	in->play->map_x = 0;
 	in->play->map_y = 0;
	in->chrono->time = 0;
	in->chrono->old_time = 0;
}

void    init_cub(t_input *in)
{
	init_vars(in);
    in->mlx = mlx_init();
    in->window = mlx_new_window(in->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
}
