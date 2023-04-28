/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:18:49 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/28 16:32:24 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void    raycast_main(void)
{
    int x;

    x = 0;
	vars()->img->img = mlx_new_image(vars()->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars()->img->addr = mlx_get_data_addr(vars()->img->img, &vars()->img->bits_per_pixel, &vars()->img->line_length, &vars()->img->endian);
    while (x < WIN_WIDTH)
    {
        raycast(x);
        x++;
    }
	mlx_put_image_to_window(vars()->mlx, vars()->window, vars()->img->img, 0, 0);
}

void    raycast(int x)
{
	int hit;
	//int side;

	vars()->play->cam_x = 2 * x / (double)WIN_WIDTH - 1;
	vars()->play->ray_d_x = vars()->play->dir_x + vars()->play->plane_x * vars()->play->cam_x;
    vars()->play->ray_d_y = vars()->play->dir_y + vars()->play->plane_y * vars()->play->cam_x;
	vars()->play->map_x = (int)vars()->play->pos_x;
	vars()->play->map_y = (int)vars()->play->pos_y;
	if (vars()->play->ray_d_x == 0)
		vars()->play->d_dist_x = DBL_MAX;
	else
		vars()->play->d_dist_x = fabs(1 / vars()->play->ray_d_x);
	if (vars()->play->ray_d_y == 0)
		vars()->play->d_dist_y = DBL_MAX;
	else
		vars()->play->d_dist_y = fabs(1 / vars()->play->ray_d_y);
    hit = 0;
    if (vars()->play->ray_d_x < 0)
    {
        vars()->play->step_x = -1;
        vars()->play->side_dist_x = (vars()->play->pos_x - vars()->play->map_x) * vars()->play->d_dist_x;
    }
    else
    {
        vars()->play->step_x = 1;
        vars()->play->side_dist_x = (vars()->play->map_x + 1.0 - vars()->play->pos_x) * vars()->play->d_dist_x;
    }
    if (vars()->play->ray_d_y < 0)
    {
        vars()->play->step_y = -1;
        vars()->play->side_dist_y = (vars()->play->pos_y - vars()->play->map_y) * vars()->play->d_dist_y;
    }
    else
    {
        vars()->play->step_y = 1;
        vars()->play->side_dist_y = (vars()->play->map_y + 1.0 - vars()->play->pos_y) * vars()->play->d_dist_y;
    }
    while (hit == 0)
    {
        if (vars()->play->side_dist_x < vars()->play->side_dist_y)
        {
            vars()->play->side_dist_x += vars()->play->d_dist_x;
            vars()->play->map_x += vars()->play->step_x;
            //side = 0;
        }
        else
        {
            vars()->play->side_dist_y += vars()->play->d_dist_y;
            vars()->play->map_y += vars()->play->step_y;
            //side = 1;
        }
        if (vars()->map[vars()->play->map_y][vars()->play->map_x] == '1')
            hit = 1;
    }
    if (vars()->play->side_dist_x < vars()->play->side_dist_y)
		vars()->play->perp_wall_dist = (vars()->play->side_dist_x - vars()->play->d_dist_x) + ((double)(vars()->play->step_x + 1) / 2.0) * vars()->play->d_dist_x;
    else
		vars()->play->perp_wall_dist = (vars()->play->side_dist_y - vars()->play->d_dist_y) + ((double)(vars()->play->step_y + 1) / 2.0) * vars()->play->d_dist_y;
	start_draw(x);
}
