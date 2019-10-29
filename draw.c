/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 10:58:29 by ihering-       #+#    #+#                */
/*   Updated: 2019/06/05 14:30:13 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		coord_x(t_fdf *fdf, int x, int y)
{
	return (fdf->startx - (fdf->gap * y) + (fdf->gap * x));
}

int		coord_y(t_fdf *fdf, int x, int y, int z)
{
	return (fdf->starty + ((fdf->gap) * x) + \
			((fdf->gap) * y)) - (z * fdf->zoom);
}

void	draw_y(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < (fdf->w - 1))
		{
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->cart[i][j].z);
			j++;
			fdf->x2 = coord_x(fdf, j, i);
			fdf->y2 = coord_y(fdf, j, i, fdf->cart[i][j].z);
			fdf->colour = colour(fdf->cart[i][j].z, fdf->cart[i][j + 1].z, fdf);
			bh_dispatch(fdf);
		}
		i++;
	}
}

void	draw_x(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < (fdf->h - 1))
	{
		j = 0;
		while (j < fdf->w)
		{
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->cart[i][j].z);
			fdf->x2 = coord_x(fdf, j, i + 1);
			fdf->y2 = coord_y(fdf, j, i + 1, fdf->cart[i + 1][j].z);
			fdf->colour = colour(fdf->cart[i][j].z, fdf->cart[i][j + 1].z, fdf);
			bh_dispatch(fdf);
			j++;
		}
		i++;
	}
}

void	draw(t_fdf *fdf)
{
	draw_y(fdf);
	draw_x(fdf);
	commandsmenu(fdf);
}
