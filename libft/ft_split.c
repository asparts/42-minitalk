/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:38:23 by mnummi            #+#    #+#             */
/*   Updated: 2023/08/07 18:47:35 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

static void	write_split(char **strs, const char *s, char c, int words)
{
	int		i;
	int		size;
	int		j;

	i = 0;
	j = -1;
	while (++j < words)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
		{
			ft_free(strs, j);
			return ;
		}
		i += size;
	}
	strs[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**strs;

	words = ft_count_words(s, c);
	strs = (char **)malloc((words + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	write_split(strs, s, c, words);
	return (strs);
}
