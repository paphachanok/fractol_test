/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:13:02 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/17 16:09:12 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_mb_member(t_fractol *frac, int num_iter)
{
	int i;
	float z_real = 0;
	float z_img = 0;
	float next_real;
	float next_img;

	i = 0;
	// while (i < num_iter && (z_real * z_real + z_img * z_img) <= 4)
	while (i < num_iter && (z_real + z_img) <= 2)
	{
		next_real = z_real * z_real - z_img * z_img + frac->complx.real;
		next_img = 2 * z_real * z_img + frac->complx.imag;
		z_real = next_real;
		z_img = next_img;
		i++;
	}
	return i;
}

// int	get_mb_member(t_fractol *frac, int num_iter)
// {
// 	int		i;
// 	float	z;
// 	float	prev_real;
// 	float	prev_img;
// 	float	next_real;
// 	float	next_img;

// 	i = 0;
// 	z = 0;
// 	next_real = 0;
// 	next_img = 0;
// 	while (i < num_iter && z <= 2)
// 	{
// 		prev_real = next_real;
// 		prev_img = next_img;
// 		next_real = sqrt(prev_real) - sqrt(prev_img) + frac->complx.real;
// 		next_img = (2 * prev_real * prev_img) + frac->complx.imag;
// 		z = next_real + next_img;
// 		i++;
// 	}
// 	return (i);
// }

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
			if (get_mb_member(frac, 20) >= 20)  // MAX(i) == 20
				my_mlx_pixel_put(frac, x, y, 0x00FF0000); // test
			re += frac->complx.real_ratio;
			x += frac->x_ratio;
		}
		im += frac->complx.imag_ratio;
		y += frac->y_ratio;
	}
	// printf("complx_img should be 1.5 => %f\n", frac->complx.imag);
	// printf("y should be 800 => %d\n", y);
}

void	mandelbrot(t_fractol *frac)
{
	float	xmin;
	float	xmax;
	float	ymin;
	float	ymax;
	int		density;

	// -2, 1.7
	xmin = -2;
	xmax = 1.7;
	ymin = -2;
	ymax = 1.7;
	density = 400;
	// 1. random x, y, density
	//  give them real_ratio, imag_ratio, x_ratio, y_ratio
	frac->x_ratio = floor(frac->mlx.size_x / density);  //! อาจจะต้องกลับมาแก้เป็น round()
	frac->y_ratio = floor(frac->mlx.size_y / density);
	frac->complx.real_ratio = fabs(xmax - xmin) / density;
	frac->complx.imag_ratio = fabs(ymax - ymin) / density;
	// printf("check img_ratio should be 0.0075 => %f\n", frac->complx.imag_ratio);
	random_complx(frac, xmin, ymin);
}
