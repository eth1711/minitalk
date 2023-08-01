/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:17:39 by etlim             #+#    #+#             */
/*   Updated: 2023/08/01 14:49:18 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnum_unsigned(unsigned long long int num, char *hex, int *count)
{
	int	len;

	len = ft_strlen(hex);
	if (num > 0)
		ft_printnum(num / len, hex, count);
	ft_printchar(hex[num % len], count);
}

void	ft_printnum(long long int num, char *hex, int *count)
{
	int	len;

	len = ft_strlen(hex);
	if (num < 0)
	{
		ft_printchar('-', count);
		num = num * -1;
		ft_printnum(num, hex, count);
	}
	else
	{
		if (num >= len)
			ft_printnum(num / len, hex, count);
		ft_printchar(hex[num % len], count);
	}
}

// int main()
// {
// 	char *hallo = "0123456789abcdef";
// 	int count = '4327';
// 	ft_printnum_unsigned(-1, hallo, &count);
// }