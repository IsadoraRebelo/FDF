/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   slopes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 11:25:00 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/06/05 11:09:28 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		m_neg(t_fdf *fdf)
{
	int inc1;
	int inc2;
	int m;
	int i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, fdf->colour);
	m = (2 * fdf->dy) - fdf->dx;
	inc1 = 2 * (fdf->dy - fdf->dx);
	inc2 = 2 * fdf->dy;
	while (i < fdf->dx)
	{
		if (m >= 0)
		{
			fdf->y1 = fdf->y1 + fdf->incy;
			m = m + inc1;
		}
		else
			m = m + inc2;
		fdf->x1 = fdf->x1 + fdf->incx;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, fdf->colour);
		i++;
	}
}

void		m_pos(t_fdf *fdf)
{
	int inc1;
	int inc2;
	int m;
	int i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, fdf->colour);
	m = (2 * fdf->dx) - fdf->dy;
	inc1 = 2 * (fdf->dx - fdf->dy);
	inc2 = 2 * fdf->dx;
	while (i < fdf->dy)
	{
		if (m >= 0)
		{
			fdf->x1 = fdf->x1 + fdf->incx;
			m = m + inc1;
		}
		else
			m = m + inc2;
		fdf->y1 = fdf->y1 + fdf->incy;
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, fdf->colour);
		i++;
	}
}

void		bh_dispatch(t_fdf *fdf)
{
	fdf->dx = fdf->x2 - fdf->x1;
	fdf->dy = fdf->y2 - fdf->y1;
	fdf->dx = abs(fdf->dx);
	fdf->dy = abs(fdf->dy);
	fdf->incx = (fdf->x2 > fdf->x1) ? 1 : -1;
	fdf->incy = (fdf->y2 > fdf->y1) ? 1 : -1;
	if (fdf->dx > fdf->dy)
		m_neg(fdf);
	else
		m_pos(fdf);
}
