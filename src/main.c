/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mavars()->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:31:54 by lleiria-          #+#    #+#             */
/*   Updated: 2023/04/21 14:52:58 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_input	*vars(void)
{
	static t_input	vars;

	return(&vars);
}

void	liberate(void)
{
	free_array(vars()->NO);
	free_array(vars()->SO);
	free_array(vars()->WE);
	free_array(vars()->EA);
	free_array(vars()->F);
	free_array(vars()->C);
	free_matrix(vars()->map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		printf("\e[1;91mError\nwrong number of arguments\n\e[0m");
	if (sort_data(av[1]) || check_map())
	{
		liberate();
		return (1);
	}
	init_cub();
	mlx_hook(vars()->window, 17, 0, ft_close, NULL);
	mlx_hook(vars()->window, 2, 1L << 0, key_press, NULL);
	raycast_main();
	liberate();
	return (0);
}
