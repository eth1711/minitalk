/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:43:25 by ethanlim          #+#    #+#             */
/*   Updated: 2023/07/26 14:48:05 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	string_send(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int c, char **str)
{
	if (c == 3)
	{
		string_send(ft_atoi(str[1]), str[2]);
		while (1)
			pause();
		return (0);
	}
	else
		ft_printf("INVALID NUMBER OF ARGUMENTS!\n");
}

	// signal(SIGUSR1, );
		// signal(SIGUSR2, );
