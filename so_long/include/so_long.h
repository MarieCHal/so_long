/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:57:37 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/03 11:56:52 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>

typedef struct s_loca
{
	int	x;
	int	y;
}			t_loca;

typedef struct s_img
{
	void	*ni;
	void	*player;
	void	*collect;
	void	*exit;
	void	*wall;
}				t_img;

typedef struct s_mlx
{
	void	*mp;
	void	*wp;
}				t_mlx;

typedef struct s_map
{
	struct s_mlx	mlx;
	void			*player;
	void			*np;
	char			**map;
	int				x;
	int				y;
	int				w;
	int				h;
	int				c;
	int				collect;
	int				exit;
}					t_map;

# define X_EVENT_KEY_PRESS 2
# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

int		main(int argc, char *argv[]);
void	so_long(char *filename);
void	putgnl(int fd, t_map *map);
int		key_press(int keycode, t_map *map);
void	validmap(t_map *map);
void	ft_error(char *message);
char	**ft_split(char const *s, char c);
void	setimg(t_img *img, t_map *map);
char	*ft_itoa(int n);
#endif
