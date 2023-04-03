/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:31:54 by lleiria-          #+#    #+#             */
/*   Updated: 2023/04/03 22:42:31 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_file(char *file)
{
	int	end;

	end = ft_strlen(file) - 1;
	if (file[end] != 'b' || file[end - 1] != 'u'
		|| file[end - 2] != 'c' || file[end - 3] != '.')
	{
		printf("\e[1;91mError\nInvalid file type\n\e[0m");
		exit(1);
	}
}

// int	file_lines(char	*file)
// {
// 	int		counter;
// 	int		fd;
// 	char	*line;

// 	counter = 0;
// 	fd = open(file, O_RDONLY);
// 	line = NULL;
// 	while ((line = get_next_line(fd)))
// 	{
// 		counter++;
// 		free(line);
// 	}
// 	if (line)
// 		free(line);
// 	close(fd);
// 	return (counter);
// }

void	liberate(t_input *in)
{
	free_array(in->NO);
	free_array(in->SO);
	free_array(in->WE);
	free_array(in->EA);
	free_array(in->F);
	free_array(in->C);
	free_matrix(in->map);
}

int	main(int ac, char **av)
{
	t_input	in;
	int		j;
	
	j = 0;
	ft_memset(&in, 0, sizeof(t_input));
	if (ac != 2)
		printf("\e[1;91mError\nwrong number of arguments\n\e[0m");
	if (sort_data(&in, av[1]) || check_map(&in))
	{
		liberate(&in);
		return (1);
	}
	printf("elementos:\n");
	printf("NO = %s\n", in.NO);
	printf("SO = %s\n", in.SO);
	printf("WE = %s\n", in.WE);
	printf("EA = %s\n", in.EA);
	printf("F = %s\n", in.F);
	printf("C = %s\n", in.C);
	printf("map:\n");
	while (in.map[j])
	{
		printf("%s\n", in.map[j]);
		j++;
	}
	// printf("Valid map\n");
	init_cub(&in);
	mlx_hook(in.window, 17, 0, ft_close, &in);
	mlx_hook(in.window, 2, 1L << 0, key_press, &in);
	mlx_loop(in.mlx);
	liberate(&in);
}