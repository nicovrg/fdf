/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:24:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/25 00:21:42 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void		move_rotate(int event, t_fdf *f)
{
	if (event == ARROW_LEFT)
		f->move_x -= 10;
	else if (event == ARROW_RIGHT)
		f->move_x += 10;
	else if (event == ARROW_DOWN)
		f->move_y += 10;
	else if (event == ARROW_UP)
		f->move_y -= 10;
	else if (event == A)
		f->rotation_y -= (10 * 3.14 / 180);
	else if (event == Q)
		f->rotation_y += (10 * 3.14 / 180);
	else if (event == Z)
		f->rotation_x -= (10 * 3.14 / 180);
	else if (event == S)
		f->rotation_x += (10 * 3.14 / 180);
	else if (event == E)
		f->rotation_z -= (10 * 3.14 / 180);
	else if (event == D)
		f->rotation_z += (10 * 3.14 / 180);
}


static void		zoom_distortion(int event, t_fdf *f)
{
	if (event == R)
		f->zoom++;
	else if (event == F)
		f->zoom--;
	else if (event == T)
		f->distortion_z += 0.2;
	else if (event == G)
		f->distortion_z -= 0.2;
}

static void		color_grid_shape(int event, t_fdf *f)
{
	if (event == Y)
	{
		if (f->color_grid == COLOR_PURPLE)
			f->color_grid = COLOR_CYAN;
		else if (f->color_grid == COLOR_CYAN)
			f->color_grid = COLOR_GREEN;
		else if (f->color_grid == COLOR_GREEN)
			f->color_grid = COLOR_WHITE;
		else if (f->color_grid == COLOR_WHITE)
			f->color_grid = COLOR_PURPLE;
	}
	else if (event == H)
	{
		if (f->color_shape == COLOR_CYAN)
			f->color_shape = COLOR_PURPLE;
		else if (f->color_shape == COLOR_PURPLE)
			f->color_shape = COLOR_GREEN;
		else if (f->color_shape == COLOR_GREEN)
			f->color_shape = COLOR_WHITE;
		else if (f->color_shape == COLOR_WHITE)
			f->color_shape = COLOR_RED;
	}
}

static void		projection_type_reset(int event, t_fdf *f)
{
	if (event == TABULATION)
	{
		if (f->projection_type == 0 || f->projection_type == 1)
			f->projection_type++;
		else
			f->projection_type = 0;
	}
	else if (event == ESPACE)
		fdf_init(f);
}

int				event_handler(int event, t_fdf *f)
{
	if (event == ESCAPE)
		return (clean_exit(f));
	move_rotate(event, f);
	zoom_distortion(event, f);
	color_grid_shape(event, f);
	projection_type_reset(event, f);
	draw_map_iterate(f);
	return (event);
}
