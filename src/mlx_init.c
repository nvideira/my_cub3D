/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:35:32 by ubuntu            #+#    #+#             */
/*   Updated: 2023/03/28 14:37:43 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    init_cub(t_mlx *mlx)
{
    mlx->mlx = mlx_init();
    mlx->window = mlx_new_window(mlx->mlx, mlx->win_wid, mlx->win_hei, "Cub3D");
}