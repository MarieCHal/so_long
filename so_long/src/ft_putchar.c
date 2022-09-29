/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:22:35 by mchalard          #+#    #+#             */
/*   Updated: 2021/12/01 15:30:12 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_putchar(char c, int char_count)
{
	write (1, &c, sizeof(char));
	char_count += 1;
	return (char_count);
}
