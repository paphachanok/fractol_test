/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:34:27 by ppoti             #+#    #+#             */
/*   Updated: 2022/09/11 11:37:40 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	find;
	char	*y;
	size_t	i;

	find = (char)c;
	y = (char *)s;
	i = 0;
	while (n > 0)
	{
		if (y[i] == find)
			return ((void *)&s[i]);
		i++;
		n--;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s", ft_memchr("www.tutorial", 46, 12));
}*/
