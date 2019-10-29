/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/18 14:20:22 by ihering-       #+#    #+#                */
/*   Updated: 2019/06/05 12:31:12 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_key(int key, t_fdf *mlx)
{
	if (key == HIGHTTUP || key == HIGHTTDOWN || key == ZOOMIN || \
		key == ZOOMOUT)
		mlx_clear_window(mlx->mlx, mlx->win);
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT || \
		key == PINK || key == BLUE || key == RED || key == YELLOW)
		mlx_clear_window(mlx->mlx, mlx->win);
}

void	ft_moves(int key, t_fdf *mlx)
{
	if (key == UP)
		mlx->startx += 5;
	if (key == DOWN)
		mlx->startx -= 5;
	if (key == RIGHT)
		mlx->starty += 5;
	if (key == LEFT)
		mlx->starty -= 5;
}

void	ft_camera(int key, t_fdf *mlx)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == HIGHTTUP)
		mlx->zoom += 1;
	if (key == HIGHTTDOWN)
		mlx->zoom -= 1;
	if (key == ZOOMIN)
	{
		if (mlx->gap == 0)
			mlx->gap = 1;
		if (mlx->gap > 1000)
		{
			draw(mlx);
			return ;
		}
		mlx->gap *= 2;
	}
	if (key == ZOOMOUT)
	{
		mlx->gap /= 2;
	}
}

void	ft_colours(int key, t_fdf *mlx)
{
	if (key == PINK)
		mlx->colour_choice = 1;
	if (key == RED)
		mlx->colour_choice = 2;
	if (key == BLUE)
		mlx->colour_choice = 3;
	if (key == YELLOW)
		mlx->colour_choice = 4;
}

int		ft_controls(int key, t_fdf *mlx)
{
	check_key(key, mlx);
	ft_camera(key, mlx);
	ft_moves(key, mlx);
	ft_colours(key, mlx);
	draw(mlx);
	return (0);
}
