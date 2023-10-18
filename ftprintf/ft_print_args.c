/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:43:01 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/17 22:55:31 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_args(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_print_int(va_arg(args, int)));
	else if (c == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}
