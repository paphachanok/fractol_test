/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:22:56 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/26 22:42:47 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../minilibx/mlx.h"
# include "../lib/libft/libft.h"

typedef struct s_mlx {
	void	*mlx_ptr;
	int		size_x;
	int		size_y;
	void	*win_ptr;
	int		color;
}	t_mlx;

typedef struct s_complx
{
	float	real;
	float	imag;
	float	real_ratio;
	float	imag_ratio;
}	t_complx;

typedef struct s_img {
	void	*img_ptr;
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
	t_complx	init_cpx;
	int			map;
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
	int			shade;
}	t_fractol;

void	my_mlx_pixel_put(t_fractol *frac, int x, int y, int color);
void	print_manual(void);
void	error_handling(t_fractol *frac);
void	frac_init(t_fractol *frac);
void	error_message(void);
void	set_map(t_fractol *frac, int ac, char **av);

int		get_mb_member(t_fractol *frac);
int		get_ju_member(t_fractol *frac);
int		get_br_member(t_fractol *frac);
void	shading(t_fractol *frac, int x, int y);
void	random_complx(t_fractol *frac, float xmin, float ymin);
void	init_map(t_fractol *frac);

int		ft_keypress(int code, t_fractol *frac);
int		close_window(t_fractol *frac);
void	mouse_complx_cal(t_fractol *frac, t_complx mouse);
int		zoom(int code, int x, int y, t_fractol *frac);
void	pan_camera(int code, t_fractol *frac);

#endif
