/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:33:07 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/07 06:26:02 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cc;
	size_t			i;

	cc = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cc[i] = c;
		i++;
	}
	return (s = cc);
}
