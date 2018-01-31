/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

t_coord		para_point(int x, int y, t_env *e)
{
	t_coord	p;
	int		z;

	z = e->mat[y][x];
	p.x = (x - e->depth * z) * e->tile_size + e->x_center / 2;
	p.y = (y - e->depth * z) * e->tile_size + e->y_center / 4;
	p.z = z;
	return (p);
}

void		draw_parallel(t_env *e)
{
	int			y;
	int			x;
	t_coord		p0;
	t_coord		p1;

	y = -1;
	while (++y < e->y_max)
	{
		x = e->x_max - 1;
		while (x >= 0)
		{
			p0 = para_point(x, y, e);
			if (y < e->y_max - 1)
			{
				p1 = para_point(x, y + 1, e);
				bresenham_line(e, p0, p1);
			}
			if (x < e->x_max - 1)
			{
				p1 = para_point(x + 1, y, e);
				bresenham_line(e, p0, p1);
			}
			x--;
		}
	}
}
