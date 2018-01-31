/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	put_z(char **line, int *x, int y, t_env *e)
{
	int		z;

	z = ft_atoi(*line);
	e->mat[y][*x] = z;
	if (z < 0)
	{
		(*line)++;
		z = -z;
	}
	while (z > 9)
	{
		z = z / 10;
		(*line)++;
	}
	*x += 1;
	(*line)++;
}

void	fill_holes(int x, int y, t_env *e)
{
	while (x < e->x_max)
	{
		e->mat[y][x] = 0;
		x++;
	}
}

int		fill_mat(int fd, t_env *e, int x, int y)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		x = 0;
		while (*line != '\0')
		{
			if (*line == ' ')
			{
				while (*line == ' ')
					line++;
			}
			else
			{
				if (*line != '-' && (*line < '0' || *line > '9'))
					return (0);
				put_z(&line, &x, y, e);
			}
			fill_holes(x, y, e);
		}
		y++;
	}
	return (1);
}
