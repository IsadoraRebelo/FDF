/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 14:35:44 by ihering-       #+#    #+#                */
/*   Updated: 2019/06/06 10:33:32 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_axes		**ft_cartesian(t_fdf *fdf, t_map *list)
{
	t_axes	**cords;

	if (!(cords = (t_axes **)malloc(sizeof(t_axes *) * (list->h + 1))))
		return (NULL);
	while (fdf->i < list->h)
	{
		cords[fdf->i] = (t_axes *)malloc(sizeof(t_axes) * (list->w + 1));
		fdf->j = 0;
		while (fdf->j < list->w)
		{
			cords[fdf->i][fdf->j].z = list->map[fdf->i][fdf->j];
			fdf->j++;
		}
		fdf->i++;
	}
	return (cords);
}

void		makefdf(t_fdf **fdf, t_map *list)
{
	(*fdf)->y1 = 0;
	(*fdf)->y2 = 0;
	(*fdf)->x1 = 0;
	(*fdf)->x2 = 0;
	(*fdf)->w = list->w;
	(*fdf)->h = list->h;
	(*fdf)->big = list->w > list->h ? list->w : list->h;
	(*fdf)->gap = list->w > list->h ? 350 / (list->w) : 350 / (list->h);
	(*fdf)->i = 0;
	(*fdf)->j = 0;
	(*fdf)->max = 700 + (*fdf)->gap * ((*fdf)->big);
	(*fdf)->maxside = (*fdf)->max - 200;
	(*fdf)->startx = (*fdf)->max / 2;
	(*fdf)->starty = (*fdf)->maxside / 6;
	(*fdf)->colour_choice = 1;
	(*fdf)->zoom = 2;
	(*fdf)->cart = ft_cartesian(*fdf, list);
	(*fdf)->mlx = mlx_init();
	(*fdf)->win = mlx_new_window((*fdf)->mlx, (*fdf)->max, \
								(*fdf)->maxside, "FDF");
}

t_fdf		*enviroment(t_map *list)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	makefdf(&fdf, list);
	return (fdf);
}
