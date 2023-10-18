/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:48:13 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/18 01:24:39 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// to print %i & %d
//nbr ->  to handle int_MIN / -2147483648
int	ft_print_int(int n)
{
	int			len;
	long int	nbr;

	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr < 10)
		len += ft_putchar(nbr + '0');
	else
	{
		len += ft_print_int(nbr / 10);
		len += ft_putchar(nbr % 10 + '0');
	}
	return (len);
}
