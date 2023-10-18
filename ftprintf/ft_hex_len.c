/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:55:24 by mnummi            #+#    #+#             */
/*   Updated: 2023/08/15 20:45:51 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// returns hex length
int	ft_hex_len(unsigned long int num)
{
	char	*ptr;
	char	buffer[50];
	char	representation[16];
	int		res;
	int		i;

	ft_strcpy(representation, "0123456789ABCDEF");
	ptr = &buffer[49];
	*ptr = '\0';
	i = 0;
	if (num <= 0)
	{
		*--ptr = '0';
		return (1);
	}
	while (num > 0)
	{
		res = num % 16;
		*--ptr = representation[res];
		num = num / 16;
		i++;
	}
	return (i);
}
