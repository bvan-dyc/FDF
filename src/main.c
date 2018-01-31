/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	fill_image(e, BLACK);
	if (e->mode == ISOMETRIC)
		draw_isometric(e);
	if (e->mode == PARALLEL)
		draw_parallel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	if (e->hidemenu == 0)
	{
		display_menu(e);
		display_data(e);
	}
	return (0);
}

int		matinit(t_env *e)
{
	e->x_center = WIN_L / 2;
	e->y_center = WIN_H / 2;
	e->red = 255;
	e->green = 255;
	e->blue = 255;
	e->btile_size = (WIN_H / e->y_max) > (WIN_L / e->x_max) ? \
		(WIN_L / (2 * e->x_max)) : (WIN_H / (2 * e->y_max));
	if (e->btile_size < 10)
		e->btile_size = 10;
	e->tile_size = e->btile_size;
	e->depth = 1;
	e->mode = ISOMETRIC;
	e->hidemenu = 0;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_L, WIN_H, "FDF");
	e->img_ptr = mlx_new_image(e->mlx, WIN_L, WIN_H);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bits_per_pixel, \
	&e->size_line, &e->endian);
	return (0);
}

int		main(int ac, char **av)
{
	t_env e;

	if (ac == 2 && av[1])
	{
		e.x_max = 0;
		if (mat_create(av[1], &e) > 0)
		{
			if (e.x_max <= 0 || e.y_max <= 0)
			{
				ft_putstr("File is not valid\n");
				exit(0);
			}
			matinit(&e);
			mlx_key_hook(e.win, key_hook, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
			mlx_loop(e.mlx);
		}
		else
			ft_putstr("Argument FD is not valid\n");
	}
	else if (ac == 1)
		ft_putstr("No File\n");
	else
		ft_putstr("FDF can only process one file\n");
	return (0);
}
