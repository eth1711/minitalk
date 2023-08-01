/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:55:40 by ethanlim          #+#    #+#             */
/*   Updated: 2023/07/26 16:32:22 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handle(int sig_usr, siginfo_t *info, void *str)
{
	static int	i = 0;
	static char	c = 0;

	(void)str;
	c |= (sig_usr == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", c);
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction		sig_action;

	ft_printf("Server PID :%i\n", getpid());
	sig_action.sa_flags = SA_SIGINFO;
	sig_action.sa_sigaction = sig_handle;
	sigaction(SIGUSR1, &sig_action, 0);
	sigaction(SIGUSR2, &sig_action, 0);
	while (1)
		pause();
	return (0);
}
