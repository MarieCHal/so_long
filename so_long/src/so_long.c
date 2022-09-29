/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:58:18 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/03 16:39:32 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit(t_map *map)
{
	free(map->map);
	exit(0);
}

void	so_long(char *filename)
{
	int		fd;
	t_map	map;
	t_img	img;
	char	*path;

	path = ft_strjoin("map/", filename);
	fd = open(path, O_RDONLY);
	free(path);
	putgnl(fd, &map);
	validmap(&map);
	map.mlx.mp = mlx_init();
	map.mlx.wp = mlx_new_window(map.mlx.mp, map.w * 60, map.h * 50, "so_long");
	setimg(&img, &map);
	mlx_key_hook(map.mlx.wp, key_press, &map);
	mlx_hook(map.mlx.wp, 17, 1L << 0, ft_exit, &map);
	mlx_loop(map.mlx.mp);
	free(map.map);
	free(&map);
	close(fd);
}
