/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:22:56 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/25 12:14:32 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>

// ! don't forget to delete
#include <stdio.h>

# include "../minilibx/mlx.h"
# include "../lib/libft/libft.h"

# define ESCAPE 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define COLOR_NEXT 13
# define COLOR_PREV 1
# define SHAD_NEXT 0
# define SHAD_PREV 2
# define ORIGIN 4

enum	e_mousedef {
	mouse_left			= 1,
	mouse_right			= 2,
	mouse_middle		= 3,
	mouse_middle_down	= 4,
	mouse_middle_up		= 5
};

typedef struct	s_mlx {
	void	*mlx_ptr;	// given after initialization
	int		size_x;
	int		size_y;
	void	*win_ptr;	// given after creating window
	int		color;
}	t_mlx;

typedef struct s_complx
{
	float	real;
	float	imag;
	float	real_ratio;
	float	imag_ratio;
}	t_complx;

// in case of we'll put another image to the same window
typedef struct	s_img {
	void	*img_ptr;	// given after creating image
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	t_mlx		mlx;
	t_img		img;
	t_complx	complx;
	int			map;  // mandebrot 0 or julia 1
	int			density;
	int			x_ratio;
	int			y_ratio;
	int			num_iter;
	int			*colors;
	float		xmin;
	float		xmax;
	float		ymin;
	float		ymax;
	float		abs_cmp_x;
	float		abs_cmp_y;
	float		zoom;
	float		new_half_w;
	float		new_half_h;
}	t_fractol;

void	my_mlx_pixel_put(t_fractol *frac, int x, int y, int color);
void	set_map(t_fractol *frac, int ac, char **av);
int		ft_keypress(int code, t_fractol *frac);
void	mandelbrot(t_fractol *frac);
void	random_complx(t_fractol *frac, float xmin, float ymin);

int		zoom(int code, int x, int y, t_fractol *frac);





#endif
