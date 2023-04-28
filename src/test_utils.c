#include "../cub3d.h"
void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	printf("  0123456789abcdefghijklmnopqrstuvwxyz\n");
	while (matrix[i])
	{
		printf("%x:%s\n", i, matrix[i]);
		i++;
	}
}
