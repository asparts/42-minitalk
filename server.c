/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:48:59 by mnummi            #+#    #+#             */
/*   Updated: 2024/03/21 11:24:52 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define _XOPEN_SOURCE 700
#include "server.h"
#include "libft/libft.h"
#include "ftprintf/ft_printf.h"
#include <unistd.h>
#include <signal.h>

/**
 * When a signal is activated, the process sends a signal to the kernel, 
 * which then utilizes the sighandler() function 
 * to perform one of three possible actions: ignore, catch, or default.
 * 
 * Note that 
 *  - static char is being initialized to \0 by default
 *  - static int is being initialized to 0 by default
 * 
 * if i == 8 -> all bits / signals received from 8-bit sequence
 * if !c -> nothing was received (all bits were 0 on client side) 
 *   -> just return sigusr2 there 
 *   -->this does nothing and makes sure that signal_info is being used.
 * void* context is being needed because function definition
 * but since it's not used -> (void) context
*/
static void	sighandler(int signal, siginfo_t *signal_info, void *context)
{
	static char	c;
	static int	i;

	(void) context;
	if (signal == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (!c)
			kill(signal_info->si_pid, SIGUSR2);
		c = 0;
		i = 0;
	}
}

/**sa_sigaction is action beign taken when signal arrives*/
/*sigaction() system call is used to change the action taken by
       a process on receipt of a specific signal.*/
/**
 * The sa_mask field indicates any signals that should be blocked 
 * while the signal handler is being executed. 
 * The sa_flags field determines a number of different things, 
 * but the important ones are 
 * - whether we get the extended information (SA_SIGINFO ) 
 * - and whether system calls that were interrupted by the signal 
 * are automatically restarted (SA_RESTART), 
 *
 * The alternative is that the interrupted system calls will fail, 
 *  restarting them is obviously a better approach.*/
int	main(int arc, char **argv)
{
	struct sigaction	sig_action;

	if (arc != 1 && argv)
		ft_printf("Wrong input. Use ./server");
	ft_printf("PID: %d\n", getpid());
	sigemptyset(&sig_action.sa_mask);
	sig_action.sa_flags = SA_RESTART | SA_SIGINFO;
	sig_action.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &sig_action, NULL);
	sigaction(SIGUSR2, &sig_action, NULL);
	while (1)
		pause();
	return (0);
}
