/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:42:53 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/17 01:12:14 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_manual()
{
	ft_putstr_fd("\n🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒\n\n", 1);
	ft_putstr_fd("\033[96m	Fractol Manual\033[0m\n", 1);
	ft_putstr_fd("	Mandelbrot Set  :  ./fractol  0\n", 1);
	ft_putstr_fd("\n🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒\n", 1);
}

void	error_handling(t_fractol *frac)
{
	if (!frac->img.img_ptr && frac->mlx.win_ptr && frac->mlx.mlx_ptr)
	{
		free(frac->mlx.mlx_ptr);
		free(frac->mlx.win_ptr);
		free(frac->img.img_ptr);
	}
	else if (!frac->mlx.win_ptr && frac->mlx.mlx_ptr)
	{
		free(frac->mlx.mlx_ptr);
		free(frac->mlx.win_ptr);
	}
	else
		free(frac->mlx.mlx_ptr);
}

// ! shorter version but does not work
// ! something is wrong about ptr
//! I think to use this verion, we should send frac->mlx as parameter at first in main()
// void	frac_init(t_fractol *frac)
// {
// 	t_mlx	mlx;
// 	t_img	img;

// 	mlx = frac->mlx;
// 	img = frac->img;
// 	mlx.mlx_ptr = mlx_init();
// 	if (!mlx.mlx_ptr)
// 	{
// 		ft_putstr_fd("Failed to initialized mlx", 2);
// 		error_handling(frac);
// 	}
// 	mlx.win_ptr = mlx_new_window(frac->mlx.mlx_ptr, frac->mlx.size_x, frac->mlx.size_y, "Hello world!");
// 	if (!mlx.win_ptr)
// 	{
// 		ft_putstr_fd("Failed to initialized window", 2);
// 		error_handling(frac);
// 	}

// 	img.img_ptr = mlx_new_image(frac->mlx.mlx_ptr, frac->mlx.size_x, frac->mlx.size_y);
// 	if (!img.img_ptr)
// 	{
// 		ft_putstr_fd("Failed to initialized image", 2);
// 		error_handling(frac);
// 	}
// 	img.img_addr = mlx_get_data_addr(frac->img.img_ptr, &frac->img.bits_per_pixel, &frac->img.line_length, &frac->img.endian);
// }

void	frac_init(t_fractol *frac)
{
	frac->mlx.mlx_ptr = mlx_init();
	if (!frac->mlx.mlx_ptr)
	{
		ft_putstr_fd("Failed to initialized mlx\n", 2);
		error_handling(frac);
	}
	frac->mlx.win_ptr = mlx_new_window(frac->mlx.mlx_ptr, frac->mlx.size_x, frac->mlx.size_y, "Hello world!");
	if (!frac->mlx.win_ptr)
	{
		ft_putstr_fd("Failed to create window\n", 2);
		error_handling(frac);
	}

	frac->img.img_ptr = mlx_new_image(frac->mlx.mlx_ptr, frac->mlx.size_x, frac->mlx.size_y);
	if (!frac->mlx.mlx_ptr)
	{
		ft_putstr_fd("Failed to create image\n", 2);
		error_handling(frac);
	}
	frac->img.img_addr = mlx_get_data_addr(frac->img.img_ptr, &frac->img.bits_per_pixel, &frac->img.line_length, &frac->img.endian);
}

void	set_map(t_fractol *frac, int ac, char **av)
{
	if (ac == 2 && av[1][0] == '0')
		frac->map = 0;
	else
	{
		ft_putstr_fd("\033[31mError:	Invalid argument\033[0m\n", 1);
		print_manual();
		exit(1);
	}
	frac_init(frac);
}
