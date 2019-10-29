/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 13:19:56 by ihering-       #+#    #+#                */
/*   Updated: 2019/06/06 12:30:06 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_map	*list;
	t_fdf	*fdf;

	if (argc != 2)
		ft_error("Error: wrong amount of arguments.");
	ft_valid(argv[1]);
	if (!(list = (t_map *)malloc(sizeof(t_map))))
		ft_error("Error: malloc failed");
	ft_store(argv[1], list);
	fdf = enviroment(list);
	draw(fdf);
	mlx_key_hook(fdf->win, ft_controls, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
