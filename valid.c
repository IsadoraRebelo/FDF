/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 13:36:51 by ihering-       #+#    #+#                */
/*   Updated: 2019/06/06 13:48:02 by ivan-tey      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_valid(char *str)
{
	int i;

	i = 0;
	if (!str)
		ft_error("Error: empty string");
	while (str[i] != '\0')
	{
		if ((str[i] == '-' && (!ft_isdigit(str[i + 1]))) || \
			str[i] == '\t')
			ft_error("Error: wrong character");
		i++;
	}
}

void	ft_check_lines(int fd, int l, int l1, t_map *cour)
{
	if (get_next_line(fd, &(cour->line)))
	{
		ft_check_valid(cour->line);
		if ((cour->coord = ft_strsplit(cour->line, ' ')) == NULL || \
			!*cour->coord)
			ft_error("Error: next line is empty");
		if (!(l = find_length(cour->coord)))
			ft_error("Error: different lengths");
		ft_strarrdel(&cour->coord);
		free(cour->line);
	}
	else
		ft_error("Error: empyt file");
	while (get_next_line(fd, &cour->line))
	{
		ft_check_valid(cour->line);
		if ((cour->coord = ft_strsplit(cour->line, ' ')) == NULL || \
			!cour->coord)
			ft_error("Error: next line is empty");
		l1 = find_length(cour->coord);
		if (l != l1)
			ft_error("Error: different lengths");
		ft_strarrdel(&cour->coord);
		free(cour->line);
	}
}

void	ft_valid(char *argv)
{
	int				fd;
	int				l;
	int				l1;
	t_map			cour;

	l = 0;
	l1 = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_error("Error: can't open the file");
	ft_check_lines(fd, l, l1, &cour);
}
