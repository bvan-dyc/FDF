/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	mat_size(int fd, t_env *e)
{
	int		x;
	int		y;
	int		i;
	char	*line;

	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		x = 0;
		while (line[i] != '\0')
		{
			if (line[i] == '-' || (line[i] >= '0' && *line <= '9'))
				x++;
			while (line[i + 1] != '\0' &&
	(line[i] == '-' || (line[i] >= '0' && line[i] <= '9')))
				i++;
			i++;
		}
		if (x > e->x_max)
			e->x_max = x;
		y++;
	}
	e->y_max = y;
}

int		**matrice_alloc(t_env *e)
{
	int **map;
	int i;

	i = 0;
	map = (int **)malloc((e->y_max) * sizeof(int *));
	while (i < e->y_max)
	{
		map[i] = (int *)malloc((e->x_max) * sizeof(int));
		i++;
	}
	return (map);
}

int		mat_create(char *file, t_env *e)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == 0)
	{
		close(fd);
		return (0);
	}
	mat_size(fd, e);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == 0)
	{
		close(fd);
		return (0);
	}
	e->mat = matrice_alloc(e);
	fill_mat(fd, e, 0, 0);
	close(fd);
	return (1);
}
