/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

static void	arrow_keys(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
		e->y_center += 3 * (WIN_H / 10);
	if (keycode == KEY_DOWN)
		e->y_center -= 3 * (WIN_H / 10);
	if (keycode == KEY_LEFT)
		e->x_center += WIN_L / 10;
	if (keycode == KEY_RIGHT)
		e->x_center -= WIN_L / 10;
}

static void	rgb_keys(int keycode, t_env *e)
{
	if (keycode == KEY_R && e->red <= 250)
		e->red += 5;
	if (keycode == KEY_R && e->red == 255)
		e->red = 0;
	if (keycode == KEY_G && e->green <= 250)
		e->green += 5;
	if (keycode == KEY_G && e->green == 255)
		e->green = 0;
	if (keycode == KEY_B && e->blue <= 250)
		e->blue += 5;
	if (keycode == KEY_B && e->blue == 255)
		e->blue = 0;
}

static void	letter_keys(int keycode, t_env *e)
{
	if (keycode == KEY_MINUS && e->tile_size > e->btile_size / 5)
		e->tile_size -= e->btile_size / 10;
	if (keycode == KEY_PLUS && e->tile_size < WIN_H)
		e->tile_size += e->btile_size / 10;
	if (keycode == KEY_P && e->mode == ISOMETRIC)
		e->mode = PARALLEL;
	else if (keycode == KEY_P)
		e->mode = ISOMETRIC;
	if (keycode == KEY_A)
		e->depth -= 0.1;
	if (keycode == KEY_D)
		e->depth += 0.1;
	if (keycode == KEY_H)
		e->hidemenu = (e->hidemenu == 0 ? 1 : 0);
}

static void	special_keys(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	if (keycode == KEY_DELETE)
	{
		e->x_center = WIN_L / 2;
		e->y_center = WIN_H / 2;
		e->red = 255;
		e->green = 255;
		e->blue = 255;
		e->tile_size = e->btile_size;
		e->depth = 1;
	}
}

int			key_hook(int keycode, t_env *e)
{
	arrow_keys(keycode, e);
	rgb_keys(keycode, e);
	letter_keys(keycode, e);
	special_keys(keycode, e);
	expose_hook(e);
	return (0);
}
