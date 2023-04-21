/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:18:49 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/21 11:28:44 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void    raycast_main(t_input *in)
{
    int x;

    x = 0;
	
	in->img->img = mlx_new_image(in->mlx, WIN_WIDTH, WIN_HEIGHT);
	in->img->addr = mlx_get_data_addr(in->img->img, &in->img->bits_per_pixel, &in->img->line_length, &in->img->endian);
    while (x < WIN_WIDTH)
    {
        raycast(in, x);
        x++;
    }
	mlx_put_image_to_window(in->mlx, in->window, in->img->img, 0, 0);
}

void    raycast(t_input *in, int x)
{
	int hit;
	int side;

	in->play->cam_x = 2 * x / (double)WIN_WIDTH - 1;
	in->play->ray_d_x = in->play->dir_x + in->play->plane_x * in->play->cam_x;
    in->play->ray_d_y = in->play->dir_y + in->play->plane_y * in->play->cam_x;
	if (in->play->ray_d_x == 0)
		in->play->d_dist_x = DBL_MAX;
	else
		in->play->d_dist_x = fabs(1 / in->play->ray_d_x);
	if (in->play->ray_d_y == 0)
		in->play->d_dist_y = DBL_MAX;
	else
		in->play->d_dist_y = fabs(1 / in->play->ray_d_y);
    hit = 0;
    if (in->play->ray_d_x < 0)
    {
        in->play->step_x = -1;
        in->play->side_dist_x = (in->play->pos_x - in->play->map_x) * in->play->d_dist_x;
    }
    else
    {
        in->play->step_x = 1;
        in->play->side_dist_x = (in->play->map_x + 1.0 - in->play->pos_x) * in->play->d_dist_x;
    }
    if (in->play->ray_d_y < 0)
    {
        in->play->step_y = -1;
        in->play->side_dist_y = (in->play->pos_y - in->play->map_y) * in->play->d_dist_y;
    }
    else
    {
        in->play->step_y = 1;
        in->play->side_dist_y = (in->play->map_y + 1.0 - in->play->pos_y) * in->play->d_dist_y;
    }
    while (hit == 0)
    {
        if (in->play->side_dist_x < in->play->side_dist_y)
        {
            in->play->side_dist_x += in->play->d_dist_x;
            in->play->map_x += in->play->step_x;
            side = 0;
        }
        else
        {
            in->play->side_dist_y += in->play->d_dist_y;
            in->play->map_y += in->play->step_y;
            side = 1;
        }
        if (in->map[in->play->map_y][in->play->map_x] == '1')
            hit = 1;
    }
    if (side == 0)
		in->play->perp_wall_dist = (in->play->map_x - in->play->pos_x + (1 - in->play->step_x) / 2) / in->play->ray_d_x;
    else
	{
        in->play->perp_wall_dist = (in->play->map_y - in->play->pos_y + (1 - in->play->step_y) / 2) / in->play->ray_d_y;
	}
	start_draw(in, x);
}
