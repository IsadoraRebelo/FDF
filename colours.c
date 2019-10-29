/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colours.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-tey <ivan-tey@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 13:10:46 by ivan-tey       #+#    #+#                */
/*   Updated: 2019/06/06 11:47:16 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		colour_pink(int z1, int z2)
{
	int	distance;
	int c1;
	int c2;
	int c3;

	distance = (z1 - z2);
	c1 = 0xf7cde1;
	c2 = 0xe276a9;
	c3 = 0xea2383;
	if (z1 > 0)
		return (c1);
	if (z1 < 0)
		return (c3);
	return (c2);
}

int		colour_red(int z1, int z2)
{
	int	distance;
	int c1;
	int c2;
	int c3;

	distance = (z1 - z2);
	c1 = 0xff6d70;
	c2 = 0xff0006;
	c3 = 0x4f0204;
	if (z1 > 0)
		return (c1);
	if (z1 < 0)
		return (c3);
	return (c2);
}

int		colour_blue(int z1, int z2)
{
	int	distance;
	int c1;
	int c2;
	int c3;

	distance = (z1 - z2);
	c1 = 0x9ab9f4;
	c2 = 0x497fe5;
	c3 = 0x00369b;
	if (z1 > 0)
		return (c1);
	if (z1 < 0)
		return (c3);
	return (c2);
}

int		colour_yellow(int z1, int z2)
{
	int	distance;
	int c1;
	int c2;
	int c3;

	distance = (z1 - z2);
	c1 = 0xefe6b1;
	c2 = 0xffde26;
	c3 = 0xff8c00;
	if (z1 > 0)
		return (c1);
	if (z1 < 0)
		return (c3);
	return (c2);
}

int		colour(int z1, int z2, t_fdf *fdf)
{
	int colour;

	if (fdf->colour_choice == 1)
		colour = colour_pink(z1, z2);
	if (fdf->colour_choice == 2)
		colour = colour_red(z1, z2);
	if (fdf->colour_choice == 3)
		colour = colour_blue(z1, z2);
	if (fdf->colour_choice == 4)
		colour = colour_yellow(z1, z2);
	return (colour);
}
