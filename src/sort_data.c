/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:09:34 by lleiria-          #+#    #+#             */
/*   Updated: 2023/04/10 16:05:29 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_not_allright(t_input *in)
{
	if (in->NO == NULL || in->SO == NULL || in->WE == NULL
		|| in->EA == NULL || in->F == NULL || in->C == NULL)
		return (msg_error("\e[1;91mError\nwrong number of elements\n\e[0m"));
	return (0);
}

void	is_element(t_input *in, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && in->NO == NULL)
		in->NO = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO ", 3) && in->SO == NULL)
		in->SO = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE ", 3) && in->WE == NULL)
		in->WE = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA ", 3) && in->EA == NULL)
		in->EA = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "F ", 2) && in->F == NULL)
		in->F = ft_strdup(line + 2);
	else if (!ft_strncmp(line, "C ", 2) && in->C == NULL)
		in->C = ft_strdup(line + 2);
}

int	putt_elems(t_input *in, char **tmp)
{
	int	i;

	i = -1;
	in->lines = matrix_size(tmp) - 6;
	while (++i <= 5)
		is_element(in, tmp[i]);
	if (is_not_allright(in))
	{
		free_matrix(tmp);
		return (msg_error("\e[1;91mError\nElements can't be stored\n\e[0m"));
	}
	in->map = malloc(sizeof(char **) * (in->lines + 1));
	if (!in->map)
		return (msg_error(strerror(errno)));
	in->map[in->lines] = NULL;
	while (tmp[i] && i < in->lines + 6)
	{
		in->map[i - 6] = ft_strdup(tmp[i]);
		i++;
	}
	free_matrix(tmp);
	return (0);
}

int	sort_data(t_input *in, char *file)
{
	int		fd;
	int		i;
	char	**tmp;
	char	*map_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (msg_error(strerror(errno)));
	in->lines = file_lines(file);
	tmp = malloc(sizeof(char *) * (in->lines + 1));
	tmp[in->lines] = NULL;
	i = -1;
	map_line = get_next_line(fd);
	while (map_line)
	{
		if (map_line[0] != '\n' && in->lines > 0)
		{
			tmp[++i] = ft_strdup_cub(map_line);
			in->lines--;
		}
		free(map_line);
		map_line = get_next_line(fd);
	}
	return (putt_elems(in, tmp));
}

void	find_player(t_input *in)
{
	int	i;
	int	j;

	i = -1;
	while (in->map[++i])
	{
		j = -1;
		while (in->map[i][++j])
		{
			if (in->map[i][j] == 'N' || in->map[i][j] == 'S'
				|| in->map[i][j] == 'E' || in->map[i][j] == 'W')
			{
				in->play->pos_x = j + 0.5;
				in->play->pos_y = i + 0.5;
				in->play->st_dir = in->map[i][j];
				in->map[i][j] = '0';
			}
		}
	}
}