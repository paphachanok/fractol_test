/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:05:47 by ppoti             #+#    #+#             */
/*   Updated: 2022/09/24 00:22:19 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_a_word(char const *s, char c)
{	
	size_t	j;
	char	*word;
	size_t	len;

	j = 0;
	len = ft_len(s, c);
	word = (char *)malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	while (j < len)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**result;

	j = 0;
	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			result[j++] = ft_a_word(s, c);
		while (*s != c && *s)
			s++;
	}
	result[j] = NULL;
	return (result);
}

// int	main(int argc, char **argv)
// {
// 	int		index;
// 	char	**split;

// 	(void)argc;
// 	split = ft_split(argv[1], ' ');
// 	index = 0;
// 	while (split[index])
// 	{
// 		printf("%s\n", split[index]);
// 		index++;
// 	}
// }
