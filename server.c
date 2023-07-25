/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:55:40 by ethanlim          #+#    #+#             */
/*   Updated: 2023/07/25 18:49:03 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s_action(int sig)
{
}

int	main(void)
{
	struct sigaction		sig_action;

	ft_printf("This is my pid :%i\n", getpid());
	sig_action.sa_flags = SA_SIGINFO;
	sig_action.sa_sigaction = s_action;
	sigaction(SIGUSR1, &s_action, 0);
	sigaction(SIGUSR2, &s_action, 0);
}
