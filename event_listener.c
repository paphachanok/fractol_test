/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:51:18 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/16 20:31:13 by ppoti            ###   ########.fr       */
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
