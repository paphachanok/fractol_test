/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:13:02 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/17 11:48:00 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	abso(float xmin, float xmax)
{
	if (xmax - xmin < 0)
		return ((xmax - xmin) * -1);
	return (xmax - xmin);
}

void	random_complx(t_fractol *frac, float xmin, float ymin)
{
	int		x;
	int		y;
	int		re;
	int		im;

	y = 0;
	im = 0;
	while (y < frac->mlx.size_y)
	{
		frac->complx.imag = ymin + im;
		x = 0;
		re = 0;
		while (x < frac->mlx.size_x)
		{
			my_mlx_pixel_put(frac, x, y, 0x00FF0000); // test
			frac->complx.real = xmin + re;
			re += frac->complx.real_ratio;
			x += frac->x_ratio;
		}
		im += frac->complx.imag_ratio;
		y += frac->y_ratio;
	}
}

void	mandelbrot(t_fractol *frac)
{
	int	density;

	density = 400;
	// 1. random x, y, density
	//  give them real_ratio, imag_ratio, x_ratio, y_ratio
	frac->x_ratio = frac->mlx.size_x / density;  //! อาจจะต้องกลับมาแก้เป็น round()
	frac->y_ratio = frac->mlx.size_y / density;
	frac->complx.real_ratio = abso(-1.5, 1.5) / density;  //! ถ้าบรรทัดพอค่อยมาตั้ง xmax xmin
	frac->complx.imag_ratio = abso(-1.5, 1.5) / density;  //! ถ้าบรรทัดพอค่อยมาตั้ง ymax ymin
	random_complx(frac, -1.5, -1.5);
}
