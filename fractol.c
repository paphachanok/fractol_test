/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:21:09 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/17 11:45:51 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *frac, int x, int y, int color)
{
	char	*dst;
	t_img	img;

	img = frac->img;
	dst = img.img_addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//! don't forget to delete
void	loop_square(t_fractol *frac, int wid, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < wid)
		{
			my_mlx_pixel_put(frac, x, y, color);
			x++;
		}
		y++;
	}
}

void	go_to_map(t_fractol *frac)
{
	if (frac->map == 0)
		mandelbrot(frac);
}

int	main(int ac, char **av)
{
	t_fractol	frac;

	frac.mlx.size_x = 800;
	frac.mlx.size_y = 800;
	set_map(&frac, ac, av);
	// printf("-> %d\n", frac.map);
	go_to_map(&frac);
	// loop_square(&frac, 200, 300, 0x00FF0000);
	mlx_put_image_to_window(frac.mlx.mlx_ptr, frac.mlx.win_ptr, frac.img.img_ptr, 0, 0);
	mlx_hook(frac.mlx.win_ptr, 2, (1L<<0), ft_keypress, &frac);
	mlx_loop(frac.mlx.mlx_ptr);
}
