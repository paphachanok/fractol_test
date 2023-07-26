/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:42:53 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/26 22:22:52 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_manual(void)
{
	ft_putstr_fd("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" \
	"  * \033[1;37m               created by ppoti\033[0m               *\n" \
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" \
	"\n\033[1;35m.d888                           888    d8b        888 \n" \
	"\033[1;35md88P\"                           888    88P        888 \n" \
	"\033[1;35m888                             888    8P         888\n" \
	"\033[1;35m888888 888d888 8888b.   .d8888b 888888 \"  .d88b.  888 \n" \
	"\033[1;35m888    888P\"      \"88b d88P\"    888      d88\"\"88b 888\n" \
	"\033[1;35m888    888    .d888888 888      888      888  888 888\n" \
	"\033[1;33m888    888    888  888 Y88b.    Y88b.    Y88..88P 888 \n" \
	"\033[1;33m888    888    \"Y888888  \"Y8888P  \"Y888    \"Y88P\"  88\033[0m\n", 1);
	ft_putstr_fd("\n🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊\n\n", 1);
	ft_putstr_fd("\033[96m fract'ol manual\033[0m\n", 1);
	ft_putstr_fd(" Mandelbrot Set  :  ./fractol  0\n", 1);
	ft_putstr_fd(" Julia Set  	:  ./fractol  1  [-2000,2000]\
 [-2000,2000] \n", 1);
	ft_putstr_fd(" Burning Luna  :  ./fractol  2\n", 1);
	ft_putstr_fd("\n🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊 🐒 🐵 🙈 🙉 🙊\n", 1);
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

void	frac_init(t_fractol *frac)
{
	frac->mlx.mlx_ptr = mlx_init();
	if (!frac->mlx.mlx_ptr)
	{
		ft_putstr_fd("Failed to initialized mlx\n", 2);
		error_handling(frac);
	}
	frac->mlx.win_ptr = mlx_new_window(frac->mlx.mlx_ptr,
			frac->mlx.size_x, frac->mlx.size_y, "fract'ol");
	if (!frac->mlx.win_ptr)
	{
		ft_putstr_fd("Failed to create window\n", 2);
		error_handling(frac);
	}
	frac->img.img_ptr = mlx_new_image(frac->mlx.mlx_ptr,
			frac->mlx.size_x, frac->mlx.size_y);
	if (!frac->mlx.mlx_ptr)
	{
		ft_putstr_fd("Failed to create image\n", 2);
		error_handling(frac);
	}
	frac->img.img_addr = mlx_get_data_addr(frac->img.img_ptr, &frac
			->img.bits_per_pixel, &frac->img.line_length, &frac->img.endian);
}

void	error_message(void)
{
	ft_putstr_fd("\n\033[31mError: Invalid arguments\033[0m\n", 1);
	print_manual();
	exit(1);
}

void	set_map(t_fractol *frac, int ac, char **av)
{
	frac->map = -1;
	frac->shade = 1;
	if (ac == 2 && !av[1][0])
		error_message();
	if (ac == 2 && ft_strncmp(av[1], "0", ft_strlen(av[1])) == 0)
		frac->map = 0;
	if (ac == 2 && ft_strncmp(av[1], "2", ft_strlen(av[1])) == 0)
		frac->map = 2;
	if (ac == 4 && ft_strncmp(av[1], "1", ft_strlen(av[1])) == 0)
	{
		if ((ft_atoi(av[2]) >= -2000 && ft_atoi(av[2]) <= 2000)
			&& (ft_atoi(av[3]) >= -2000 && ft_atoi(av[3]) <= 2000))
		{
			frac->map = 1;
			frac->init_cpx.real = (float) ft_atoi(av[2]) / 1000.0;
			frac->init_cpx.imag = (float) ft_atoi(av[3]) / 1000.0;
		}
	}
	if (frac->map != 0 && frac->map != 1 && frac->map != 2)
		error_message();
	frac_init(frac);
}
