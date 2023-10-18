/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:53:25 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/27 08:40:41 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// %u

long int	ft_print_unsigned(long int u)
{
	int			len;

	len = 0;
	if (u < 0)
	{
		len += ft_putchar('-');
	}
	if (u < 10)
		len += ft_putchar(u + '0');
	else
	{
		len += ft_print_int(u / 10);
		len += ft_putchar(u % 10 + '0');
	}
	return (len);
}
