/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:13:02 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/25 13:22:28 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_mb_member(t_fractol *frac)
{
	int i;
	float z_real;
	float z_img;
	float next_real;
	float next_img;

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
	return i;
}

void	mb_shading(t_fractol *frac, int x, int y)
{
	int		loop_num;

	loop_num = get_mb_member(frac);
	my_mlx_pixel_put(frac, x, y, frac->colors[loop_num % 5]); // test
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
			mb_shading(frac, x, y);
			re += frac->complx.real_ratio;
			x += frac->x_ratio;
		}
		im += frac->complx.imag_ratio;
		y += frac->y_ratio;
	}
}

void	mandelbrot(t_fractol *frac)
{
	frac->xmin = -2;
	frac->xmax = 2;
	frac->ymin = -2;
	frac->ymax = 2;
	frac->density = 800;
	frac->num_iter = 30;
	frac->zoom = 1;
	// 1. random x, y, density
	//  give them real_ratio, imag_ratio, x_ratio, y_ratio
	frac->x_ratio = floor(frac->mlx.size_x / frac->density);  //! อาจจะต้องกลับมาแก้เป็น round()
	frac->y_ratio = floor(frac->mlx.size_y / frac->density);
	frac->complx.real_ratio = fabs(frac->xmax - frac->xmin) / frac->density;
	frac->complx.imag_ratio = fabs(frac->ymax - frac->ymin) / frac->density;
	random_complx(frac, frac->xmin, frac->ymin);
}
