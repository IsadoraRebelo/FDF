/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 10:17:01 by ihering-       #+#    #+#                */
/*   Updated: 2019/06/06 13:50:20 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>
# include "./minilibx/mlx.h"

# define HIGHTTUP 24
# define HIGHTTDOWN 27
# define ZOOMIN 34
# define ZOOMOUT 31
# define DOWN 123
# define UP 124
# define RIGHT 125
# define LEFT 126
# define PINK 35
# define RED 15
# define BLUE 11
# define YELLOW 16

typedef struct		s_axes
{
	float	z;
}					t_axes;

typedef struct		s_fdf
{
	t_axes	**cart;
	float	y1;
	float	x1;
	float	y2;
	float	x2;
	float	z1;
	int		w;
	int		h;
	int		i;
	int		j;
	int		dy;
	int		dx;
	int		big;
	int		gap;
	int		incx;
	int		incy;
	int		startx;
	int		starty;
	int		colour;
	int		colour_choice;
	int		zoom;
	float	max;
	float	maxside;
	void	*mlx;
	void	*win;
}					t_fdf;

typedef struct		s_map
{
	int		w;
	int		h;
	int		hmax;
	int		hmin;
	int		**map;
	char	*line;
	char	**coord;
}					t_map;

void				ft_valid(char *argv);
void				ft_error(char *str);
int					find_length(char **coord);
t_fdf				*enviroment(t_map *m);
void				ft_store(char *av, t_map *list);
void				draw(t_fdf *fdf);
void				bh_dispatch(t_fdf *fdf);
int					ft_controls(int key, t_fdf *mlx);
int					colour(int z1, int z2, t_fdf *fdf);
void				commandsmenu(t_fdf *fdf);
void				free_cords(int fd, t_map *list);

#endif
