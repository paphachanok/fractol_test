/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_luna.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:13:27 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/26 17:47:20 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complx	complex_exp(t_complx z)
{
	float		exp_real;
	t_complx	result;

	exp_real = exp(z.real);
	result.real = exp_real * cos(z.imag);
	result.imag = exp_real * sin(z.imag);
	return (result);
}

t_complx	complex_add(t_complx a, t_complx b)
{
	t_complx	result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

t_complx	complex_mul_conju(t_complx a, t_complx b)
{
	t_complx	result;

	result.real = a.real * b.real - a.imag * (b.imag * -1);
	result.imag = a.real * (b.imag * -1) + a.imag * b.real;
	return (result);
}

t_complx	complex_div(t_complx a, t_complx b)
{
	float		b_squred;
	t_complx	numer_x_conju;
	t_complx	result;

	b_squred = b.real * b.real + b.imag * b.imag;
	numer_x_conju = complex_mul_conju(a, b);
	result.real = numer_x_conju.real / b_squred;
	result.imag = numer_x_conju.imag / b_squred;
	return (result);
}

int	get_br_member(t_fractol *frac)
{
	int			i;
	t_complx	z;
	t_complx	numer;
	t_complx	deno;

	i = 0;
	z.real = frac->complx.real;
	z.imag = frac->complx.imag;
	while (i < 80 && (z.real * z.real + z.imag * z.imag) <= 4)
	{
		numer = z;
		deno = complex_add(complex_exp(z), frac->complx);
		z = complex_div(numer, deno);
		i++;
	}
	return (i);
}
