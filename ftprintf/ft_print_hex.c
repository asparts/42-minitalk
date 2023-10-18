/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:53:39 by mnummi            #+#    #+#             */
/*   Updated: 2023/08/15 20:45:02 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// for printing %x and %X
//doing this printing here, 
int	ft_print_hex(unsigned long int num, int lowercase)
{
	char	*ptr;
	char	buffer[50];
	char	representation[16];
	int		res;
	int		i;

	i = ft_hex_len(num);
	if (lowercase == 1)
		ft_strcpy(representation, "0123456789abcdef");
	else
		ft_strcpy(representation, "0123456789ABCDEF");
	ptr = &buffer[49];
	*ptr = '\0';
	if (num <= 0)
		return (write(1, "0", 1));
	while (num > 0)
	{
		res = num % 16;
		*--ptr = representation[res];
		num = num / 16;
	}
	return (write(1, ptr, i));
}
