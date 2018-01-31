/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	pixel_put(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < WIN_L && y >= 0 && y < WIN_H)
	{
		pos = (x * e->bits_per_pixel / 8) + (y * e->size_line);
		e->img[pos] = color;
		e->img[pos + 1] = color >> 8;
		e->img[pos + 2] = color >> 16;
	}
}

void	fill_image(t_env *e, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_L)
		{
			pixel_put(e, x, y, color);
			x++;
		}
		y++;
	}
}
