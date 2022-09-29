/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:36:45 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/03 12:11:35 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	imgtowin(t_img img, t_loca l, t_map *map, char c)
{
	int	x;
	int	y;

	x = 60;
	y = 50;
	if (c == '1' || c == 'C' || c == 'E')
	{
		if (c == '1')
			img.ni = mlx_xpm_file_to_image (map->mlx.mp, img.wall, &x, &y);
		if (c == 'C')
			img.ni = mlx_xpm_file_to_image (map->mlx.mp, img.collect, &x, &y);
		if (c == 'E')
			img.ni = mlx_xpm_file_to_image (map->mlx.mp, img.exit, &x, &y);
		mlx_put_image_to_window (map->mlx.mp, map->mlx.wp, img.ni, l.x, l.y);
	}
	else if (c == 'P')
	{
		img.ni = mlx_xpm_file_to_image(map->mlx.mp, map->player, &x, &y);
		mlx_put_image_to_window (map->mlx.mp, map->mlx.wp, img.ni, l.x, l.y);
		map->np = img.ni;
		map->x = l.x;
		map->y = l.y;
	}
}

void	imgletters(t_map *map, t_img img)
{
	int		j;
	int		i;
	char	*message;

	map->x = 0;
	map->y = 0;
	j = 0;
	message = "number of moves: ";
	while (j < map->h)
	{
		i = 0;
		while (map->map [j][i])
		{
			if (map->map[j][i] != '0')
				imgtowin(img, (t_loca){i * 60, j * 50}, map, map->map[j][i]);
			i++;
		}
		j++;
	}
	mlx_string_put(map->mlx.mp, map->mlx.wp, 5, 10, 0xAAAAAA, message);
}

void	setimg(t_img *img, t_map *map)
{
	img->collect = "img/collect.xpm";
	img->exit = "img/exit.xpm";
	img->wall = "img/wall.xpm";
	map->player = "img/player.xpm";
	imgletters(map, *img);
}
