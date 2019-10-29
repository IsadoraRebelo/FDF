/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   menu.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 15:58:24 by ihering-       #+#    #+#                */
/*   Updated: 2019/06/06 13:23:54 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	commandsmenu(t_fdf *fdf)
{
	int		i;
	void	*mlx;
	void	*win;

	i = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 30, i += 20, 0xEAEAEA, "HOW TO USE:");
	mlx_string_put(mlx, win, 30, i += 30, 0xEAEAEA, "- Move with arrows");
	mlx_string_put(mlx, win, 30, i += 20, 0xEAEAEA, \
					"- Change hight with + and -");
	mlx_string_put(mlx, win, 30, i += 20, 0xEAEAEA, \
					"- Zoom in and out with I and O");
	mlx_string_put(mlx, win, 30, i += 20, 0xEAEAEA, \
					"- Colours: B, P, R and Y");
}
