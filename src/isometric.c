/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

static t_coord	iso_point(int x, int y, t_env *e)
{
	t_coord ip;
	int		z;

	z = e->mat[y][x];
	ip.x = (((x - y) * (e->tile_size / 2))) + e->x_center;
	ip.y = (x + y) * (e->tile_size / 2) - z * (e->tile_size / 2) \
	* e->depth + e->y_center / 4;
	ip.z = z;
	return (ip);
}

void			bresenham_line(t_env *e, t_coord p0, t_coord p1)
{
	t_brnh b;

	b.delta.x = abs(p1.x - p0.x);
	b.delta.y = abs(p1.y - p0.y);
	b.slope.y = p0.y < p1.y ? 1 : -1;
	b.slope.x = p0.x < p1.x ? 1 : -1;
	b.err = (b.delta.x > b.delta.y ? b.delta.x : -b.delta.y) / 2;
	b.sw = 0;
	while (b.sw == 0)
	{
		pixel_put(e, p0.x, p0.y, convert_rgb(e->red, e->green, e->blue));
		if (p0.x == p1.x && p0.y == p1.y)
			b.sw = 1;
		b.e2 = b.err;
		if (b.sw == 0 && b.e2 > -b.delta.x)
		{
			b.err -= b.delta.y;
			p0.x += b.slope.x;
		}
		if (b.sw == 0 && b.e2 < b.delta.y)
		{
			b.err += b.delta.x;
			p0.y += b.slope.y;
		}
	}
}

void			iso_landr(t_env *e, t_coord *p, int x_offset, int y_offset)
{
	t_coord p0;
	t_coord p1;

	p0.x = p->x + x_offset;
	p0.y = p->y + y_offset;
	p1.x = p->x + x_offset - 1;
	p1.y = p->y + y_offset - 1;
	if (p->x + x_offset != 0)
		bresenham_line(e, iso_point(p0.x, p0.y, e), iso_point(p1.x, p0.y, e));
	if (!(p->y + y_offset == 0 && p->x + x_offset != 0))
		bresenham_line(e, iso_point(p0.x, p0.y, e), iso_point(p0.x, p1.y, e));
}

void			draw_isometric(t_env *e)
{
	t_coord p;
	int		x_offset;
	int		y_offset;

	p.x = e->x_max - 1;
	p.y = e->y_max - 1;
	while (!(p.x == 0 && p.y == 0))
	{
		x_offset = 0;
		y_offset = 0;
		while (p.x + x_offset < e->x_max && p.y + y_offset >= 0)
		{
			iso_landr(e, &p, x_offset, y_offset);
			x_offset++;
			y_offset--;
		}
		if (p.x > 0 && p.y == e->y_max - 1)
			p.x--;
		else if (p.x == 0)
			p.y--;
	}
}
