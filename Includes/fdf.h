/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"

# define WIN_L		1280
# define WIN_H		720

# define BLACK		0x1B2631
# define WHITE		0xFFFFFF
# define RED		0xFF5733
# define GREEN		0x28B463
# define BLUE		0x2E86C1
# define YELLOW		0xF1C40F
# define PURPLE		0x7D3C98
# define ORANGE		0xF39C12
# define PINK		0xEC7063

# define KEY_ESC	53
# define KEY_DELETE	51
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_A		0
# define KEY_B		11
# define KEY_C		8
# define KEY_D		2
# define KEY_G		5
# define KEY_H		4
# define KEY_I		34
# define KEY_N		45
# define KEY_P		35
# define KEY_R		15
# define KEY_T		17
# define KEY_W		13
# define KEY_PLUS	69
# define KEY_MINUS	78

# define ISOMETRIC	1
# define PARALLEL	0

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**mat;
	int			x_max;
	int			y_max;
	int			x_center;
	int			y_center;
	int			red;
	int			green;
	int			blue;
	int			tile_size;
	int			btile_size;
	double		depth;
	int			mode;
	int			hidemenu;
	void		*img_ptr;
	char		*img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_env;

typedef struct	s_coord
{
	int			x;
	int			y;
	int			z;
}				t_coord;

typedef struct	s_brnh
{
	t_coord delta;
	t_coord slope;
	int		sw;
	int		err;
	int		e2;
}				t_brnh;

int				fill_mat(int fd, t_env *e, int x, int y);
int				mat_create(char *file, t_env *e);
void			pixel_put(t_env *e, int x, int y, int color);
void			draw_isometric(t_env *e);
void			draw_parallel(t_env *e);
int				key_hook(int keycode, t_env *e);
void			fill_image(t_env *e, int color);
void			pixel_put(t_env *e, int x, int y, int color);
void			color_put(t_env *e, t_coord p0, t_coord p1);
int				expose_hook(t_env *e);
unsigned long	convert_rgb(int red, int green, int blue);
void			bresenham_line(t_env *e, t_coord p0, t_coord p1);
void			display_data(t_env *e);
void			display_menu(t_env *e);

#endif
