/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:08:21 by lleiria-          #+#    #+#             */
/*   Updated: 2023/05/01 23:02:22 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <time.h>
# include <math.h>
# include <ctype.h>
# include <limits.h>
# include <float.h>

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define PI 3.14159265358979323846
# define TWO_PI 6.28318530717958647692

//screen
# define FOV_ANGLE (PI / 3)
# define WIN_WIDTH 2600
# define WIN_HEIGHT 1400
# define TILE_SIZE 64

//key codes
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

//color codes
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define YELLOW 0xFFFF00
# define PURPLE 0xFF00FF
# define CYAN 0x00FFFF
# define ORANGE 0xFFA500
# define BROWN 0xA52A2A
# define PINK 0xFFC0CB
# define GREY 0x808080
# define DARK_GREY 0x404040
# define LIGHT_GREY 0xC0C0C0
# define DARK_BLUE 0x0000A0
# define DARK_GREEN 0x008000
# define DARK_RED 0x800000
# define DARK_YELLOW 0x808000
# define DARK_PURPLE 0x800080

typedef struct s_player
{
	double	cam_x;
	double	dir_x;
	double	dir_y;
	double	ray_d_x;
	double	ray_d_y;
	double	side_dist_x;
	double	side_dist_y;
	double	d_dist_x;
	double	d_dist_y;
	int		step_x;
	int		step_y;
	double	plane_x;
	double	plane_y;
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	perp_wall_dist;
	int		hit;
	int		side;
}	t_player;

typedef struct s_graph
{
	int	line_height;
	int	draw_start;
	int	draw_end;
}	t_graph;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_time
{
	clock_t	time;
	clock_t	old_time;
	double	frame_time;
	double	move_speed;
	double	rot_speed;
}	t_time;

typedef struct s_input
{
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;
	char		**map;
	int			lines;
	void		*mlx;
	void		*window;
	char		st_dir;
	t_img		*img;
	t_time		*chrono;
	t_player	*play;
	t_graph		*graph;
}	t_input;

/*----______----------_______--__----_-----_______--------_______----_______--________--
-----/  ___  \-------/  __   |-\ \--| |---/  _____|------/  __   |--/  ____/-|__    __|-
----/  /__/  /------/  /  |  |--\ \-| |--/  /-----------/  /  |  |-|  |___------|  |----
---/  ___   /------/  /___|  |---\ \| |-|  |-----------/  /___|  |--\___  \-----|  |----
--/  /---\  \-----/  _____   |----\   |-|  |----------/  _____   |------\  |----|  |----
-/  /-----\  \---/  /-----|  |-----|  |--\  \_____---/  /-----|  |--____/  /----|  |----
/__/-------\__\-/__/------|__|-----|__|---\_______|-/__/------|__|-|______/-----|__|----*/

t_input	*vars(void);

//raycast.c
void    raycast_main(void);
void    raycast(int x); //-----> work in progress

//draw.c
void	put_stripe(int x, int color);
void	start_draw(int x, int side);
void	my_mlx_pixel_put(int x, int y, int color);

//exit.c
int		msg_error(char *message);
void	free_matrix(char **matrix);
void	free_array(char *str);

//check_map.c
int		check_map(void);

//check_map_utils.c
int		abnormalities(char **map);
int		extreme_lines(char **map, int line);
int		validate(char x, int is_wall);
int		not_solo(void);
void	check_file(char *file);

//sort_data.c
int		sort_data(char *file);
void	find_player(void);
int		is_not_alright(void);

//parsing_utils.c
int		matrix_size(char **matrix);
char	*ft_strdup_cub(const char *s1);
int		file_lines(char *file);

//mlx_init.c
void    init_cub(void);
void    init_vars(void);
void	define_dir_values(void);

//keys.c
int		ft_close(void);
int		key_press(int keycode);
void	rotate(int dir);
void	move_fwd(void);
void	fps_count(void);

#endif
