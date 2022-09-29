/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:04:15 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/03 12:08:15 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(0);
}

//checks if the borders have 1
void	checkborder(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map.map[0][i] && map.map[map.h - 1][i])
	{
		if (map.map[0][i] != '1' || map.map[map.h - 1][i] != '1')
			ft_error("the map is not surounded by walls");
		i++;
	}
	while (j < map.h)
	{
		if (map.map[j][0] != '1' || map.map[j][map.w - 1] != '1')
			ft_error("the map is not surounded by walls");
		j++;
	}
}

//checks the number of each letter
void	numbercheck(t_map *map)
{
	int	i;
	int	j;
	int	pcount;
	int	ecount;

	j = 0;
	pcount = 0;
	ecount = 0;
	while (j < map->h)
	{
		i = 0;
		while (map->map [j][i])
		{
			if (map->map[j][i] == 'P')
				pcount++;
			if (map->map[j][i] == 'E')
				ecount++;
			if (map->map[j][i] == 'C')
				map->collect = map->collect + 1;
			i++;
		}
		j++;
	}
	if (pcount != 1 || ecount != 1 || map->collect < 1)
		ft_error("invalid map");
}

//checks if the map contains only 1, 0, E, P, C
void	checkletters(t_map map)
{
	int	j;
	int	i;

	j = 0;
	while (j < map.h)
	{
		i = 0;
		while (map.map[j][i])
		{
			if (map.map[j][i] != '0' && map.map[j][i] != '1' &&
		map.map[j][i] != 'E' && map.map[j][i] != 'C' &&
		map.map[j][i] != 'P')
				ft_error("the map contains unknown characters");
			i++;
		}
		j++;
	}
}

void	validmap(t_map *map)
{
	if (map->h == 0 || map->w == 0)
		ft_error("no map");
	if (map->w < map->h)
		ft_error("the map isn't rectangular");
	checkletters(*map);
	checkborder(*map);
	numbercheck(map);
}
