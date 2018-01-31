/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

void	display_rgb(t_env *e)
{
	mlx_string_put(e->mlx, e->win, WIN_L - 220, 20, WHITE, "R:");
	mlx_string_put(e->mlx, e->win, WIN_L - 190, 20, RED,
	ft_itoa(e->red));
	mlx_string_put(e->mlx, e->win, WIN_L - 150, 20, WHITE, "G:");
	mlx_string_put(e->mlx, e->win, WIN_L - 120, 20, GREEN,
	ft_itoa(e->green));
	mlx_string_put(e->mlx, e->win, WIN_L - 80, 20, WHITE, "B:");
	mlx_string_put(e->mlx, e->win, WIN_L - 50, 20, BLUE,
	ft_itoa(e->blue));
}

void	display_camera(t_env *e)
{
	mlx_string_put(e->mlx, e->win, WIN_L - 220, 65, WHITE, "CAMERA:");
	if (e->y_center <= (WIN_H / 2))
	{
		mlx_string_put(e->mlx, e->win, WIN_L - 140, 65, WHITE,
	ft_itoa((WIN_H / 8) - (e->y_center / 4)));
		mlx_string_put(e->mlx, e->win, WIN_L - 100, 65, RED, "S");
	}
	if (e->y_center > (WIN_H / 2))
	{
		mlx_string_put(e->mlx, e->win, WIN_L - 140, 65, WHITE,
	ft_itoa((e->y_center / 4) - (WIN_H / 8)));
		mlx_string_put(e->mlx, e->win, WIN_L - 100, 65, BLUE, "N");
	}
	if (e->x_center <= (WIN_L / 2))
	{
		mlx_string_put(e->mlx, e->win, WIN_L - 80, 65, WHITE,
	ft_itoa((WIN_L / 2) - (e->x_center)));
		mlx_string_put(e->mlx, e->win, WIN_L - 40, 65, YELLOW, "E");
	}
	if (e->x_center > (WIN_L / 2))
	{
		mlx_string_put(e->mlx, e->win, WIN_L - 80, 65, WHITE,
	ft_itoa((e->x_center) - (WIN_L / 2)));
		mlx_string_put(e->mlx, e->win, WIN_L - 40, 65, GREEN, "W");
	}
}

void	display_data(t_env *e)
{
	display_rgb(e);
	mlx_string_put(e->mlx, e->win, WIN_L - 220, 35, WHITE,
	"ZOOM:");
	mlx_string_put(e->mlx, e->win, WIN_L - 160, 35, WHITE,
	ft_itoa(100 + 10 * ((e->tile_size - (e->btile_size))
	/ (e->btile_size / 10))));
	mlx_string_put(e->mlx, e->win, WIN_L - 120, 35, WHITE,
	"%");
	mlx_string_put(e->mlx, e->win, WIN_L - 220, 50, WHITE,
	"DEPTH:");
	mlx_string_put(e->mlx, e->win, WIN_L - 150, 50, WHITE,
	ft_itoa(e->depth * 10));
	display_camera(e);
	mlx_string_put(e->mlx, e->win, WIN_L - 220, 80, WHITE,
	"PROJECTION:");
	if (e->mode == ISOMETRIC)
		mlx_string_put(e->mlx, e->win, WIN_L - 110, 80, WHITE, " ISOMETRIC");
	if (e->mode == PARALLEL)
	{
		mlx_string_put(e->mlx, e->win, WIN_L - 110, 80, WHITE, " PARALLEL");
		mlx_string_put(e->mlx, e->win, WIN_L - 130, 95, WHITE, " (NOT VALID)");
	}
}

void	display_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, WHITE,
	"Use 'R', 'G', 'B' to increase RGB rates.");
	mlx_string_put(e->mlx, e->win, 20, 35, WHITE,
	"Use + to Zoom in and - to Zoom out");
	mlx_string_put(e->mlx, e->win, 20, 50, WHITE,
	"Use the direction pad to move around");
	mlx_string_put(e->mlx, e->win, 20, 65, WHITE,
	"Use A to decrease and D to increase depth");
	mlx_string_put(e->mlx, e->win, 20, 80, WHITE,
	"Use 'P' to change Projection mode");
	mlx_string_put(e->mlx, e->win, 20, 95, WHITE,
	"To Reset everything use the DELETE Key");
	mlx_string_put(e->mlx, e->win, 20, 110, WHITE,
	"(Use 'H' to hide the menu and data)");
}
