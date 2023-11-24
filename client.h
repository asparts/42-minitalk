/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:49:18 by mnummi            #+#    #+#             */
/*   Updated: 2023/11/24 02:20:06 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ftprintf/ft_printf.h"

int			main(int arc, char **argv);
static void	send_message(int pid, char *message, char *ending);

#endif 
