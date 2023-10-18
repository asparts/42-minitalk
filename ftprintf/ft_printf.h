/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:39:04 by mnummi            #+#    #+#             */
/*   Updated: 2023/08/15 20:56:05 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(const char *format, ...);
int			ft_putchar(char c); // %c and %%
int			ft_putstr(char *str); // %s
int			ft_print_args(char c, va_list args);
char		*ft_strcpy(char *dest, const char *src);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int			ft_print_int(int n); // %i & %d
int			ft_print_ptr(void *p); // %p
long int	ft_print_unsigned(long int u); // %u
int			ft_print_hex(unsigned long int num, int lowercase); // %x and %X
size_t		ft_strlen(const char *str);
int			ft_hex_len(unsigned long int num);
#endif
