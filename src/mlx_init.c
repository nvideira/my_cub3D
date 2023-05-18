/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:35:32 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/02 17:27:53 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	define_dir_values(void)
{
	if (vars()->st_dir == 'N')
	{
		vars()->play->dir_x = 0;
		vars()->play->dir_y = -1;
		vars()->play->plane_x = -0.66;
		vars()->play->plane_y = 0;
	}
	else if (vars()->st_dir == 'S')
	{
		vars()->play->dir_x = 0;
		vars()->play->dir_y = 1;
		vars()->play->plane_x = 0.66;
		vars()->play->plane_y = 0;
	}
	else if (vars()->st_dir == 'E')
	{
		vars()->play->dir_x = 1;
		vars()->play->dir_y = 0;
		vars()->play->plane_x = 0;
		vars()->play->plane_y = 0.66;
	}
	else if (vars()->st_dir == 'W')
	{
		vars()->play->dir_x = -1;
		vars()->play->dir_y = 0;
		vars()->play->plane_x = 0;
		vars()->play->plane_y = -0.66;
	}
}

void	init_vars(void)
{
	vars()->play = (t_player *)malloc(sizeof(t_player));
	vars()->chrono = (t_time *)malloc(sizeof(t_time));
	vars()->graph = (t_graph *)malloc(sizeof(t_graph));
	vars()->img = (t_img *)malloc(sizeof(t_img));
 	find_player();
	define_dir_values();
 	vars()->play->cam_x = 0;
 	vars()->play->ray_d_x = 0;
 	vars()->play->ray_d_y = 0;
 	vars()->play->side_dist_x = 0;
 	vars()->play->side_dist_y = 0;
 	vars()->play->d_dist_x = 0;
 	vars()->play->d_dist_y = 0;
 	vars()->play->step_x = 0;
 	vars()->play->step_y = 0;
	vars()->play->side = 0;
 	vars()->play->perp_wall_dist = 0;
 	vars()->play->hit = 0;
 	vars()->play->side = 0;
 	vars()->play->map_x = 0;
 	vars()->play->map_y = 0;
	vars()->chrono->time = 0;
	vars()->chrono->old_time = 0;
}

void    init_cub(void)
{
	init_vars();
	vars()->img = (t_img *)malloc(sizeof(t_img));
    vars()->mlx = mlx_init();
    vars()->window = mlx_new_window(vars()->mlx, WIN_WID, WIN_HEI, "Cub3D");
}
