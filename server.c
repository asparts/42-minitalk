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

/**
 * When a signal is activated, the process sends a signal to the kernel, 
 * which then utilizes the sigHandler() function 
 * to perform one of three possible actions: ignore, catch, or default.
 * 
 * Note that 
 *  - static char is being initialized to \0 by default
 *  - static int is being initialized to 0 by default
 * 
 * if i == 8 -> all bits / signals received from 8-bit sequence
 * if !c -> nothing was received (all bits were 0 on client side) 
 *   -> just return sigusr2 there
*/
static void sigHandler(int signal, siginfo_t* signalInfo, void* context)
{
	static char c;
	static int i;

	if (signal == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (!c)
			kill(signalInfo->si_pid, SIGUSR2);
		c = 0;
		i = 0;
	}
}

int main(int arc, char **argv)
{
	struct sigaction sigAction;

	if (arc != 1 && argv)
		ft_printf("Wrong input. Use ./server");
	ft_printf("PID: %d\n", getpid());
	sigemptyset(&sigAction.sa_mask);
	sigAction.sa_flags = SA_RESTART | SA_SIGINFO;
	/**sa_sigaction is action beign taken when signal arrives*/
	sigAction.sa_sigaction = sigHandler;
	/*sigaction() system call is used to change the action taken by
       a process on receipt of a specific signal.*/
	sigaction(SIGUSR1, &sigAction, NULL);
	sigaction(SIGUSR2, &sigAction, NULL);
	while (1)
		pause();
	return (0);
}
