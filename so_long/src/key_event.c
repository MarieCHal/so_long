/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:31:59 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/03 16:39:41 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
//printf the number of moves in the window
void	moves(t_map *map)
{
	int		x;
	int		y;
	void	*newimg;
	char	*moves;

	x = 60;
	y = 50;
	newimg = mlx_xpm_file_to_image(map->mlx.mp, "img/wall.xpm", &x, &y);
	mlx_put_image_to_window(map->mlx.mp, map->mlx.wp, newimg, 120, 0);
	map->c = map->c + 1;
	moves = ft_itoa(map->c);
	mlx_string_put(map->mlx.mp, map->mlx.wp, 120, 10, 0xAAAAAA, moves);
	free(moves);
}

//delete player
void	moveplayer(t_map *map, int mx, int my)
{
	int	x;
	int	y;

	x = 60;
	y = 50;
	mlx_destroy_image(map->mlx.mp, map->np);
	map->np = mlx_new_image(map->mlx.mp, x, y);
	mlx_put_image_to_window(map->mlx.mp, map->mlx.wp, map->np, mx, my);
	map->np = mlx_xpm_file_to_image(map->mlx.mp, map->player, &x, &y);
	mlx_put_image_to_window(map->mlx.mp, map->mlx.wp, map->np, map->x, map->y);
	moves(map);
}

//check if the player can move to the next tile
void	mapcheck(t_map *map, int mapx, int mapy)
{
	int	i;
	int	j;

	i = map->x / 60;
	j = map->y / 50;
	if (map->map[j][i] != '1' && map->map[j][i] != 'E' && map->map[j][i] != 'C')
		moveplayer(map, mapx, mapy);
	else if (map->map[j][i] == 'C')
	{
		moveplayer(map, mapx, mapy);
		map->exit = map->exit + 1;
		map->map[j][i] = '0';
	}
	else if (map->map[j][i] == 'E' && map->exit == map->collect)
		exit(0);
	else
	{
		map->x = mapx;
		map->y = mapy;
	}
}

//handles the key events to move arounf and close the program
int	key_press(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_S)
	{
		map->y = map->y + 50;
		mapcheck(map, map->x, map->y - 50);
	}
	if (keycode == KEY_A)
	{
		map->x = map->x - 60;
		mapcheck(map, map->x + 60, map->y);
	}
	if (keycode == KEY_W)
	{
		map->y = map->y - 50;
		mapcheck(map, map->x, map->y + 50);
	}
	if (keycode == KEY_D)
	{
		map->x = map->x + 60;
		mapcheck(map, map->x - 60, map->y);
	}
	return (0);
}
