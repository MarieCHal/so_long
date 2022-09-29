/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:07:27 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/01 13:36:22 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_putnbr(int n, int char_count)
{
	if (n == -2147483648)
		char_count = ft_putstr("-2147483648", char_count);
	else if (n < 0)
	{
		ft_putchar('-', char_count);
		char_count = ft_putnbr(-n, char_count + 1);
	}
	else if (n >= 10)
	{
		char_count = ft_putnbr(n / 10, char_count);
		char_count = ft_putchar((n % 10 + 48), char_count);
	}
	else
		char_count = ft_putchar((48 + n), char_count);
	return (char_count);
}
