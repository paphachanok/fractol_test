/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:51:18 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/20 23:48:02 by ppoti            ###   ########.fr       */
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

int	mouse_event(int code, t_fractol *frac)
{
	if (code == mouse_middle_up)
	{
		frac->xmin *= 0.8;
		frac->xmax *= 0.8;
		frac->ymin *= 0.8;
		frac->ymax *= 0.8;
	}
return (0);
}
