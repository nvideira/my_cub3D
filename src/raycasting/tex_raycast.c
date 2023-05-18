/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:17:35 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/18 12:31:52 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	tex_raycast(void)
{
	int		x;

	x = 0;
	while (x < vars()->res_x)
	{
		vars()->play->cam_x = 2 * x / (double)vars()->res_x - 1;
		vars()->play->ray_d_x = vars()->play->dir_x + vars()->play->plane_x \
			* vars()->play->cam_x;
		vars()->play->ray_d_y = vars()->play->dir_y + vars()->play->plane_y \
			* vars()->play->cam_x;
		vars()->play->map_x = (int)vars()->play->pos_x;
		vars()->play->map_y = (int)vars()->play->pos_y;
		vars()->play->d_dist_x = fabs(1 / vars()->play->ray_d_x);
		vars()->play->d_dist_y = fabs(1 / vars()->play->ray_d_y);
		tex_raycast_2();
		x++;
	}
	return ;
}
