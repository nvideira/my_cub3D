/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:09:34 by lleiria-          #+#    #+#             */
/*   Updated: 2023/04/26 10:05:07 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_not_alright(void)
{
	if (vars()->NO == NULL || vars()->SO == NULL || vars()->WE == NULL
		|| vars()->EA == NULL || vars()->F == NULL || vars()->C == NULL)
		return (msg_error("\e[1;91mError\nwrong number of elements\n\e[0m"));
	return (0);
}

void	is_element(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && vars()->NO == NULL)
		vars()->NO = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO ", 3) && vars()->SO == NULL)
		vars()->SO = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE ", 3) && vars()->WE == NULL)
		vars()->WE = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA ", 3) && vars()->EA == NULL)
		vars()->EA = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "F ", 2) && vars()->F == NULL)
		vars()->F = ft_strdup(line + 2);
	else if (!ft_strncmp(line, "C ", 2) && vars()->C == NULL)
		vars()->C = ft_strdup(line + 2);
}

int	put_elems(char **tmp)
{
	int	i;

	i = -1;
	vars()->lines = matrix_size(tmp) - 6;
	while (++i <= 5)
		is_element(tmp[i]);
	if (is_not_alright())
	{
		free_matrix(tmp);
		return (msg_error("\e[1;91mError\nElements can't be stored\n\e[0m"));
	}
	vars()->map = malloc(sizeof(char **) * (vars()->lines + 1));
	if (!vars()->map)
		return (msg_error(strerror(errno)));
	vars()->map[vars()->lines] = NULL;
	while (tmp[i] && i < vars()->lines + 6)
	{
		vars()->map[i - 6] = ft_strdup(tmp[i]);
		i++;
	}
	free_matrix(tmp);
	return (0);
}

int	sort_data(char *file)
{
	int		fd;
	int		i;
	char	**tmp;
	char	*map_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (msg_error(strerror(errno)));
	vars()->lines = file_lines(file);
	tmp = malloc(sizeof(char *) * (vars()->lines + 1));
	tmp[vars()->lines] = NULL;
	i = -1;
	map_line = get_next_line(fd);
	while (map_line)
	{
		if (map_line[0] != '\n' && vars()->lines > 0)
		{
			tmp[++i] = ft_strdup_cub(map_line);
			vars()->lines--;
		}
		free(map_line);
		map_line = get_next_line(fd);
	}
	return (put_elems(tmp));
}

void	find_player(void)
{
	int	i;
	int	j;

	i = -1;
	while (vars()->map[++i])
	{
		j = -1;
		while (vars()->map[i][++j])
		{
			if (vars()->map[i][j] == 'N' || vars()->map[i][j] == 'S'
				|| vars()->map[i][j] == 'E' || vars()->map[i][j] == 'W')
			{
				vars()->play->pos_x = (double)j + 0.5;
				vars()->play->pos_y = (double)i + 0.5;
				vars()->st_dir = vars()->map[i][j];
				vars()->map[i][j] = '0';
			}
		}
	}
}
