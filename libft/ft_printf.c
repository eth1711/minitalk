/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:13:03 by etlim             #+#    #+#             */
/*   Updated: 2023/07/25 18:51:43 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		i;

	total = 0;
	i = -1;
	va_start(args, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				ft_printchar(va_arg(args, int), &total);
			else if (format[i + 1] == 's')
				ft_printstr(va_arg(args, char *), &total);
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
				ft_printnum((long long int)va_arg(args, int),
					"0123456789", &total);
			else if (format[i + 1] == 'u')
				ft_printnum((long int)va_arg(args, unsigned int),
					"0123456789", &total);
			else if (format[i + 1] == 'x')
			{
				ft_printnum((long long int)va_arg(args, unsigned long int),
					"0123456789abcdef", &total);
			}
			else if (format[i + 1] == 'p')
			{
				total += write(1, "0x", 2);
				ft_printnum_unsigned((long int)va_arg(args, unsigned long int),
					"0123456789abcdef", &total);
			}
			else if (format[i + 1] == 'X')
			{	
				ft_printnum((long int)va_arg(args, unsigned long int),
					"0123456789ABCDEF", &total);
			}
			else if (format[i + 1] == '%')
				ft_printchar('%', &total);
			i++;
		}
		else
			ft_printchar(format[i], &total);
	}
	return (total);
	va_end(args);
}

// int main(void)
// {
// 	int mine;
// 	int original;
// 	char *str = "banana";
	
// 	original = printf("start %d %% end\n", 2147483647);
// 	mine = ft_printf("start %d %% end\n", 2147483647);
// 	printf("my count: %i, original count: %i\n", mine, original);
// }