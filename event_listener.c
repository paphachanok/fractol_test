/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:51:18 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/26 22:43:37 by ppoti            ###   ########.fr       */
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

void	pan_camera(int code, t_fractol *frac)
{
	if (code == 123)
	{
		frac->xmin -= 0.4;
		frac->xmax -= 0.4;
	}
	else if (code == 124)
	{
		frac->xmin += 0.4;
		frac->xmax += 0.4;
	}
	else if (code == 125)
	{
		frac->ymin += 0.4;
		frac->ymax += 0.4;
	}
	else if (code == 126)
	{
		frac->ymin -= 0.4;
		frac->ymax -= 0.4;
	}
	random_complx(frac, frac->xmin, frac->ymin);
	mlx_put_image_to_window(frac->mlx.mlx_ptr, frac->mlx.win_ptr,
		frac->img.img_ptr, 0, 0);
}

int	zoom(int code, int x, int y, t_fractol *frac)
{
	t_complx	mouse;

	if (code != 4 && code != 5)
		return (0);
	if (code == 4)
		frac->zoom = 1.08;
	if (code == 5)
		frac->zoom = 1 / 1.08;
	frac->abs_cmp_x = fabs(frac->xmax - frac->xmin);
	frac->abs_cmp_y = fabs(frac->ymax - frac->ymin);
	mouse.real = frac->xmin + ((float)x / (float)frac->mlx.size_x)
		* frac->abs_cmp_x;
	mouse.imag = frac->ymin + ((float)y / (float)frac->mlx.size_y)
		* frac->abs_cmp_y;
	mouse_complx_cal(frac, mouse);
	random_complx(frac, frac->xmin, frac->ymin);
	mlx_put_image_to_window(frac->mlx.mlx_ptr, frac->mlx.win_ptr,
		frac->img.img_ptr, 0, 0);
	return (0);
}

/*
	1 = S = change shading
	15 = R = reset image
	53 = ESCAPE
	123 = LEFT
	124 = RIGHT
	125 = DOWN
	126 = UP
*/

int	ft_keypress(int code, t_fractol *frac)
{
	if (code == 53)
		close_window(frac);
	if (code == 15)
		init_map(frac);
	if (code == 1)
	{
		frac->shade *= -1;
		random_complx(frac, frac->xmin, frac->ymin);
	}
	if (code >= 123 && code <= 126)
		pan_camera(code, frac);
	if (code != 53)
	{
		mlx_put_image_to_window(frac->mlx.mlx_ptr, frac->mlx.win_ptr,
			frac->img.img_ptr, 0, 0);
		mlx_hook(frac->mlx.win_ptr, 17, 0, close_window, frac);
		mlx_hook(frac->mlx.win_ptr, 2, (1L << 0), ft_keypress, frac);
		mlx_mouse_hook(frac->mlx.win_ptr, zoom, frac);
		mlx_loop(frac->mlx.mlx_ptr);
	}
	return (0);
}

void	mouse_complx_cal(t_fractol *frac, t_complx mouse)
{
	frac->xmin = mouse.real - (frac->zoom * (mouse.real - frac->xmin));
	frac->xmax = mouse.real + (frac->zoom * (frac->xmax - mouse.real));
	frac->ymin = mouse.imag - (frac->zoom * (mouse.imag - frac->ymin));
	frac->ymax = mouse.imag + (frac->zoom * (frac->ymax - mouse.imag));
	frac->complx.real_ratio = fabs(frac->xmax - frac->xmin) / frac->density;
	frac->complx.imag_ratio = fabs(frac->ymax - frac->ymin) / frac->density;
}
