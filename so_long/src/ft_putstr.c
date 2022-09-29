/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:58:02 by mchalard          #+#    #+#             */
/*   Updated: 2021/12/01 15:36:59 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_putstr(char *s, int char_count)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (char_count + 6);
	}
	while (s[i])
	{
		write (1, &s[i], sizeof(char));
		i++;
	}
	char_count += i;
	return (char_count);
}
