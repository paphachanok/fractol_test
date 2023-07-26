/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:13:02 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/26 18:11:16 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_mb_member(t_fractol *frac)
{
	int		i;
	float	z_real;
	float	z_img;
	float	next_real;
	float	next_img;

	i = 0;
	z_real = 0;
	z_img = 0;
	while (i < frac->num_iter && (z_real * z_real + z_img * z_img) <= 4)
	{
		next_real = (z_real * z_real) - (z_img * z_img) + frac->complx.real;
		next_img = (2 * z_real * z_img) + frac->complx.imag;
		z_real = next_real;
		z_img = next_img;
		i++;
	}
	return (i);
}

int	get_ju_member(t_fractol *frac)
{
	int		i;
	float	z_real;
	float	z_img;
	float	next_real;
	float	next_img;

	i = 0;
	z_real = frac->complx.real;
	z_img = frac->complx.imag;
	while (i < frac->num_iter && (z_real * z_real + z_img * z_img) <= 4)
	{
		next_real = (z_real * z_real) - (z_img * z_img) + frac->init_cpx.real;
		next_img = (2 * z_real * z_img) + frac->init_cpx.imag;
		z_real = next_real;
		z_img = next_img;
		i++;
	}
	return (i);
}

void	shading(t_fractol *frac, int x, int y)
{
	int		loop_num;

	if (frac->map == 0)
		loop_num = get_mb_member(frac);
	else if (frac->map == 1)
		loop_num = get_ju_member(frac);
	else if (frac->map == 2)
		loop_num = get_br_member(frac);
	if (frac->shade == 1)
		my_mlx_pixel_put(frac, x, y, frac->colors[loop_num % 4]);
	else if (frac->shade == -1)
	{
		if (loop_num >= 0.9 * (float)frac->num_iter)
			my_mlx_pixel_put(frac, x, y, 0x00000000);
		else if (loop_num >= 0.7 * (float)frac->num_iter)
			my_mlx_pixel_put(frac, x, y, 0x000D1282);
		else if (loop_num >= 0.5 * (float)frac->num_iter)
			my_mlx_pixel_put(frac, x, y, 0x00EEEDED);
		else if (loop_num >= 0.3 * (float)frac->num_iter)
			my_mlx_pixel_put(frac, x, y, 0x00F0DE36);
		else if (loop_num >= 0.2 * (float)frac->num_iter)
			my_mlx_pixel_put(frac, x, y, 0x00D71313);
		else
			my_mlx_pixel_put(frac, x, y, 0x00000000);
	}
}

void	random_complx(t_fractol *frac, float xmin, float ymin)
{
	int		x;
	int		y;
	float	re;
	float	im;

	y = 0;
	im = 0;
	while (y < frac->mlx.size_y)
	{
		frac->complx.imag = ymin + im;
		x = 0;
		re = 0;
		while (x < frac->mlx.size_x)
		{
			frac->complx.real = xmin + re;
			shading(frac, x, y);
			re += frac->complx.real_ratio;
			x += frac->x_ratio;
		}
		im += frac->complx.imag_ratio;
		y += frac->y_ratio;
	}
}

void	init_map(t_fractol *frac)
{
	frac->xmin = -2;
	frac->xmax = 2;
	frac->ymin = -2;
	frac->ymax = 2;
	frac->density = 800;
	frac->num_iter = 80;
	frac->zoom = 1;
	frac->x_ratio = floor(frac->mlx.size_x / frac->density);
	frac->y_ratio = floor(frac->mlx.size_y / frac->density);
	frac->complx.real_ratio = fabs(frac->xmax - frac->xmin) / frac->density;
	frac->complx.imag_ratio = fabs(frac->ymax - frac->ymin) / frac->density;
	random_complx(frac, frac->xmin, frac->ymin);
}
