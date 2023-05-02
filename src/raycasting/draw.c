/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:42:35 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/02 14:25:39 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	start_draw(int x, int side)
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
	if (side == 0)
		color /= 3;
	put_stripe(x, color);
}
void	put_stripe(int x, int color)
{
	int y;

	y = vars()->graph->draw_start;
	while (y < vars()->graph->draw_end)
	{
		my_mlx_pixel_put(x, y, color);
		y++;
	}
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = vars()->img->addr + (y * vars()->img->line_length + x * (vars()->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
