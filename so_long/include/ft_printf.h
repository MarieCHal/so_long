/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:50:24 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/01 13:32:05 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//int		main(void);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c, int char_count);
int		ft_putstr(char *s, int char_count);
int		ft_putnbr(int n, int char_count);

#endif
