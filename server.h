/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:49:09 by mnummi            #+#    #+#             */
/*   Updated: 2024/03/21 10:32:58 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
/** _GNU_SOURCE is needed for signal.h / sigaction 
-> otherwise getting error of incomplete type from struct sigaction*/
//#define _GNU_SOURCE 
# include <signal.h>

int				main(int arc, char **argv);
static void		sighandler(int signal, siginfo_t *signalInfo, void *context);
#endif
