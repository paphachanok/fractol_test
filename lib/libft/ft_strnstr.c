/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:36:39 by ppoti             #+#    #+#             */
/*   Updated: 2022/09/24 15:11:00 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!hay && len == 0)
		return (0);
	if (*needle == 0)
		return ((char *)hay);
	while (hay[i] != '\0')
	{
		j = 0;
		if (hay[i] == needle[j])
		{
			while (hay[i + j] == needle[j] && (i + j) < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)(hay + i));
			}
		}
		i++;
	}
	return (NULL);
}
