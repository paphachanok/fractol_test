/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:24:42 by ppoti             #+#    #+#             */
/*   Updated: 2022/08/27 15:33:13 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	a;
	unsigned char	b;

	a = '0';
	b = '0';
	while (a == b && n > 0)
	{
		a = *s1++;
		b = *s2++;
		if (a == '\0')
			return (a - b);
		n--;
	}
	return (a - b);
}
