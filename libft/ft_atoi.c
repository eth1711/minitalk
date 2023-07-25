/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:36:15 by etlim             #+#    #+#             */
/*   Updated: 2023/07/24 13:22:16 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
	{
		res = (res * 10 + (str[i] - '0'));
		i++;
	}
	return (res * sign);
}

/* #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char str[] = "22";
	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
} */