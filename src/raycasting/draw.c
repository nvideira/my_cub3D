/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:42:35 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/21 10:35:07 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	start_draw(t_input *in, int x)
{
	int color;

	color = PURPLE;
	in->graph->line_height = (int)(WIN_HEIGHT / in->play->perp_wall_dist);
	in->graph->draw_start = -in->graph->line_height / 2 + WIN_HEIGHT / 2;
	if (in->graph->draw_start < 0)
		in->graph->draw_start = 0;
	in->graph->draw_end = in->graph->line_height / 2 + WIN_HEIGHT / 2;
	if (in->graph->draw_end >= WIN_HEIGHT)
		in->graph->draw_end = WIN_HEIGHT - 1;
	if (in->play->side == 1)
		color = color / 2;
	put_stripe(x, in, color);
}

void	put_stripe(int x, t_input *in, int color)
{
	int y;

	y = in->graph->draw_start;
	while (y < in->graph->draw_end)
	{
		my_mlx_pixel_put(in, x, y, color);
		y++;
	}
}

void	fps_count(t_input *in)
{
	in->chrono->old_time = in->chrono->time;
	in->chrono->time = clock();
	in->chrono->frame_time = (double)(in->chrono->time - in->chrono->old_time) / CLOCKS_PER_SEC;
	in->chrono->move_speed = in->chrono->frame_time * 5.0;
	in->chrono->rot_speed = in->chrono->frame_time * 3.0;
}

void	my_mlx_pixel_put(t_input *in, int x, int y, int color)
{
	char	*dst;

	dst = in->img->addr + (y * in->img->line_length + x * (in->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
