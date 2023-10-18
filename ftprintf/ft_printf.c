/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:44:46 by mnummi            #+#    #+#             */
/*   Updated: 2023/07/16 12:55:33 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
	/* 
	* va_list holds the information needed by va_start, va_arg, 
	* va_end, and va_copy
	*/
//if --> When you encounter a %, there is a variable to print.
// else -- > Loop through a string. 
//   As long as the string is not a %, keep printing what you read
//va_end before return -->  
//  va_end macro performs cleanup for an ap object initialized 
//  by a call to va_start or va_copy.

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_print_args(format[i + 1], args);
			i++;
		}
		else
		{
			len += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
