/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:42:35 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/27 12:50:12 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	start_draw(int x)
{
	int color;

	color = PURPLE;
	vars()->graph->line_height = (int)(WIN_HEIGHT / vars()->play->perp_wall_dist);
	vars()->graph->draw_start = -vars()->graph->line_height / 2 + WIN_HEIGHT / 2;
	if (vars()->graph->draw_start < 0)
		vars()->graph->draw_start = 0;
	vars()->graph->draw_end = vars()->graph->line_height / 2 + WIN_HEIGHT / 2;
	if (vars()->graph->draw_end >= WIN_HEIGHT)
		vars()->graph->draw_end = WIN_HEIGHT - 1;
	//if (vars()->play->side == 1)
	//	color = color / 2;
	put_stripe(x, color);
}
void	put_stripe(int x, int color)
{
	int y;

	y = vars()->graph->draw_start;
	while (y < vars()->graph->draw_end)
	{
		//printf("x: %d, y: %d, color: %d\n", x, y, color);
		my_mlx_pixel_put(x, y, color);
		y++;
		//color += y;
	}
}

void	fps_count()
{
	vars()->chrono->old_time = vars()->chrono->time;
	vars()->chrono->time = clock();
	vars()->chrono->frame_time = (double)(vars()->chrono->time - vars()->chrono->old_time) / CLOCKS_PER_SEC;
	vars()->chrono->move_speed = vars()->chrono->frame_time * 5.0;
	vars()->chrono->rot_speed = vars()->chrono->frame_time * 3.0;
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = vars()->img->addr + (y * vars()->img->line_length + x * (vars()->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
