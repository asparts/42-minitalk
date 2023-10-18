/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:52:52 by mnummi            #+#    #+#             */
/*   Updated: 2023/08/15 20:55:00 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *p)
{
	unsigned long long	ptr_address;
	int					len;

	len = 0;
	if (p == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ptr_address = (unsigned long long)p;
	len += ft_putstr("0x");
	len += ft_print_hex(ptr_address, 1);
	return (len);
}
