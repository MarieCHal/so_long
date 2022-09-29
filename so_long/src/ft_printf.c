/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:51:08 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/01 13:38:18 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_treat(char c, va_list args, int char_count)
{
	if (c == 'c')
		char_count = ft_putchar(va_arg(args, int), char_count);
	if (c == 's')
		char_count = ft_putstr(va_arg(args, char *), char_count);
	if (c == 'd' || c == 'i')
		char_count = ft_putnbr(va_arg(args, int), char_count);
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;
	int		i;
	char	*s;

	char_count = 0;
	i = 0;
	s = (char *)format;
	va_start(args, format);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			char_count = ft_treat(s[i + 1], args, char_count);
			i++;
		}
		else
			char_count = ft_putchar(s[i], char_count);
		i++;
	}
	va_end(args);
	return (char_count);
}
