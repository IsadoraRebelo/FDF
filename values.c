/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   values.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 10:30:30 by ihering-       #+#    #+#                */
/*   Updated: 2019/06/06 11:50:49 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*atoil(char **coord, int w)
{
	int *map;
	int i;

	i = 0;
	map = (int *)malloc(sizeof(int) * (w + 1));
	if (map == NULL)
		return (NULL);
	while (i < w)
	{
		map[i] = ft_atoi(&coord[i][0]);
		i++;
	}
	return (map);
}

void	free_cords(int fd, t_map *list)
{
	int		i;
	char	*line;
	char	**coord;

	i = 0;
	list->map = (int **)malloc(sizeof(int *) * (list->h + 1));
	if (list->map == NULL)
		return ;
	while (get_next_line(fd, &line))
	{
		coord = ft_strsplit(line, ' ');
		list->map[i] = atoil(coord, list->w);
		ft_strarrdel(&coord);
		free(line);
		i++;
	}
	close(fd);
}

int		find_length(char **coord)
{
	int	x;

	x = 0;
	while (coord[x])
		x++;
	return (x);
}

void	find_height(int fd, t_map *list)
{
	int		y;
	char	*line;
	char	**coord;

	y = 0;
	if (get_next_line(fd, &line))
	{
		y++;
		coord = ft_strsplit(line, ' ');
		list->w = find_length(coord);
		ft_strarrdel(&coord);
		free(line);
	}
	while (get_next_line(fd, &line))
	{
		y++;
		free(line);
	}
	list->h = y;
	close(fd);
}

void	ft_store(char *av, t_map *list)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error("Error: can't open the file");
	find_height(fd, list);
	fd = open(av, O_RDONLY);
	free_cords(fd, list);
}
