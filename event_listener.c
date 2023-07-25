/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:51:18 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/25 12:23:13 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *frac)
{
	if (frac->img.img_ptr)
		mlx_destroy_image(frac->mlx.mlx_ptr, frac->img.img_ptr);
	mlx_destroy_window(frac->mlx.mlx_ptr, frac->mlx.win_ptr);
	free(frac->mlx.mlx_ptr);
	exit(0);
}

int	ft_keypress(int code, t_fractol *frac)
{
	if (code == ESCAPE)
		close_window(frac);
	return(0);
}

int	zoom(int code, int x, int y, t_fractol *frac)
{
	// t_complx	mouse;

	printf("=> code: %d, x: %d, y: %d\n", code, x, y);
	if (code != 4 && code != 5)
		return (0);

	if (code == 5)
		frac->zoom += 0.000005;
	if (code == 4 && frac->zoom > 0)
		frac->zoom -= 0.000005;
	frac->abs_cmp_x = fabs(frac->xmax - frac->xmin);
	frac->abs_cmp_y = fabs(frac->ymax - frac->ymin);
	frac->new_half_w = (frac->xmax - frac->xmin) / (2 * frac->zoom);
	frac->new_half_h =  (frac->ymax - frac->ymin) / (2 * frac->zoom);

	frac->xmin = (((float)x / (float)frac->mlx.size_x) * frac->abs_cmp_x) + frac->xmin - frac->new_half_w;
	frac->xmax = (((float)x / (float)frac->mlx.size_x) * frac->abs_cmp_x) + frac->xmin + frac->new_half_w;
	frac->ymin = (((float)x / (float)frac->mlx.size_x) * frac->abs_cmp_y) + frac->ymin - frac->new_half_h;
	frac->ymax = (((float)x / (float)frac->mlx.size_x) * frac->abs_cmp_y) + frac->ymin + frac->new_half_h;
	frac->complx.real_ratio = fabs(frac->xmax - frac->xmin) / frac->density;
	frac->complx.imag_ratio = fabs(frac->ymax - frac->ymin) / frac->density;

	//! ohm
	// mouse.real = frac->xmin + ((x / (float)frac->mlx.size_x) * (frac->xmax - frac->xmin));
	// mouse.imag = frac->ymin + ((frac->mlx.size_y - y) / (float)frac->mlx.size_y - y) * ((frac->ymax - frac->ymin));
	// frac->xmin = mouse.real - (frac->zoom * (mouse.real - frac->xmin));
	// frac->xmax = mouse.real - (frac->zoom * (frac->xmax - mouse.real));
	// frac->ymin = mouse.imag - (frac->zoom * (mouse.imag - frac->ymin));
	// frac->ymax = mouse.imag - (frac->zoom * (frac->ymax - mouse.imag));
	printf("=> xmin: %f, ymin: %f\n", frac->xmin, frac->ymin);
	random_complx(frac, frac->xmin, frac->ymin);
	mlx_put_image_to_window(frac->mlx.mlx_ptr, frac->mlx.win_ptr, frac->img.img_ptr, 0, 0);
	return (0);
}
