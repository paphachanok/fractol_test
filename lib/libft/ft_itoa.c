/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:38:09 by ppoti             #+#    #+#             */
/*   Updated: 2022/09/24 01:01:14 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_len(int n)
{
	long	tmp;
	int		len;

	tmp = n;
	len = 0;
	if (n <= 0)
	{
		tmp *= -1;
		len++;
	}
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	tmp;
	int		len;
	char	*dest;

	tmp = n;
	len = ft_num_len(n);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (0);
	if (n < 0)
		tmp *= -1;
	dest[len] = '\0';
	while (len > 0)
	{
		dest[len - 1] = (tmp % 10) + '0';
		tmp /= 10;
		len--;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// }
