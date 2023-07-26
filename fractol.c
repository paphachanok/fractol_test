/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:21:09 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/26 18:08:03 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *frac, int x, int y, int color)
{
	char	*dst;
	t_img	img;

	img = frac->img;
	dst = img.img_addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	t_fractol	frac;

	frac.mlx.size_x = 800;
	frac.mlx.size_y = 800;
	frac.colors = (int [4]){0x000d0404, 0x00c01404,
		0x00e5b627, 0x00620604};
	set_map(&frac, ac, av);
	init_map(&frac);
	mlx_put_image_to_window(frac.mlx.mlx_ptr, frac.mlx.win_ptr,
		frac.img.img_ptr, 0, 0);
	mlx_hook(frac.mlx.win_ptr, 17, 0, close_window, &frac);
	mlx_hook(frac.mlx.win_ptr, 2, (1L << 0), ft_keypress, &frac);
	mlx_mouse_hook(frac.mlx.win_ptr, zoom, &frac);
	mlx_loop(frac.mlx.mlx_ptr);
	return (0);
}
