/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:43:02 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/07 18:33:04 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	start = (char *) s1;
	end = start + ft_strlen(s1);
	while (*start && ft_isinset(*start, set))
		++start;
	while (start < end && ft_isinset(*(end - 1), set))
		--end;
	str = ft_substr(start, 0, end - start);
	return (str);
}
