/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:04:14 by ppoti             #+#    #+#             */
/*   Updated: 2022/09/24 15:29:43 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = (void *)malloc(size * count);
	if (!dest)
		return (NULL);
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	ft_bzero(dest, count * size);
	return (dest);
}
