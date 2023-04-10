/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:18:49 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/10 15:24:26 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void    raycast_main(t_input *in)
{
    int x;

    x = 0;
    while (x < WIN_WIDTH)
    {
        raycast(in, x);
        x++;
    }
}

void    raycast(t_input *in, int x)
{
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
    double delta_dist_x;
    double delta_dist_y;
    double perp_wall_dist;
    int hit;
    int side;

    camera_x = 2 * x / (double)WIN_WIDTH - 1;
    ray_dir_x = in->play->dir_x + in->play->plane_x * camera_x;
    ray_dir_y = in->play->dir_y + in->play->plane_y * camera_x;
    delta_dist_x = fabs(1 / ray_dir_x);
    delta_dist_y = fabs(1 / ray_dir_y);
    hit = 0;
    if (ray_dir_x < 0)
    {
        in->step_x = -1;
        in->side_dist_x = (in->play->pos_x - in->map_x) * delta_dist_x;
    }
    else
    {
        in->step_x = 1;
        in->side_dist_x = (in->map_x + 1.0 - in->play->pos_x) * delta_dist_x;
    }
    if (ray_dir_y < 0)
    {
        in->step_y = -1;
        in->side_dist_y = (in->play->pos_y - in->map_y) * delta_dist_y;
    }
    else
    {
        in->step_y = 1;
        in->side_dist_y = (in->map_y + 1.0 - in->play->pos_y) * delta_dist_y;
    }
    while (hit == 0)
    {
        if (in->side_dist_x < in->side_dist_y)
        {
            in->side_dist_x += delta_dist_x;
            in->map_x += in->step_x;
            side = 0;
        }
        else
        {
            in->side_dist_y += delta_dist_y;
            in->map_y += in->step_y;
            side = 1;
        }
        if (in->map[in->map_y][in->map_x] == '1')
            hit = 1;
    }
    if (side == 0)
        perp_wall_dist = (in->map_x - in->play->pos_x + (1 - in->step_x) / 2) / ray_dir_x;
    else
        perp_wall_dist = (in->map_y - in->play->pos_y + (1 - in->step_y) / 2) / ray_dir_y;
}