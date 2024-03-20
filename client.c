/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnummi <mnummi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:49:05 by mnummi            #+#    #+#             */
/*   Updated: 2024/03/21 10:22:13 by mnummi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

/**
 * Sending msg char by char  signals
 *
 * notice bitwise operator & which returns 
 1 only if both bits are true
*/
/**
*so for example, if we want to send 
 char e (decimal: 101, binary:01100101)
*we start to compare it from first bit 
 to the left shifted 1 bit 
*and if they're both 1, we send 
 sigusr1 signal with kill (signal.h)
*
*serverside code receives sigusr1 
so we can handle received signals there 
*(we do same kind of bin -> char conversion 
in serverside code based on received signals)
*/
static void	send_message(int pid, char *message, char *ending)
{
	int	i;
	int	bit;

	i = 0;
	while (message[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (message[i] & (1 << bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(250);
		}
		usleep(250);
		i++;
	}
	if (ending)
		send_message(pid, ending, NULL);
}

int	main(int arc, char **argv)
{
	if (arc != 3)
	{
		ft_printf("Wrong number of arguments! ");
		ft_printf("Correct format is ./client <PID> [your message here]!");
	}
	else
		send_message(ft_atoi(argv[1]), argv[2], "\n\0");
	return (0);
}
