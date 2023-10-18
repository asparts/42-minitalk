/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:48:59 by mnummi            #+#    #+#             */
/*   Updated: 2023/10/18 08:00:48 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft/libft.h"
#include "ftprintf/ft_printf.h"
#include <unistd.h>

int main(int arc, char **argv)
{
	ft_printf("PID: %d\n", getpid());
	return (0);
}
