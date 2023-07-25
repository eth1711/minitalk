/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifbt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:20:37 by ethanlim          #+#    #+#             */
/*   Updated: 2023/07/24 13:31:36 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdarg.h> //for va_arg(printf)
#include <stdio.h>

int     ft_atoi(char *str);
int     ft_strlen(char *s);
int     ft_printf(const char *format, ...);
void	ft_printchar(char c, int *count);
void    ft_printstr(char *s, int *count);
void    ft_printnum(long long int num, char *hex, int *count);
void    ft_printnum_unsigned(unsigned long long int num, char *hex, int *count);

#endif