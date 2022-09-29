/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:17:23 by mchalard          #+#    #+#             */
/*   Updated: 2022/03/03 16:41:28 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	setmap(t_map *map)
{
	map->h = 0;
	map->w = 0;
	map->collect = 0;
	map->c = 0;
	map->exit = 0;
}

void	checkwidth(t_map *map, char *str, char *result)
{
	if (str && (int)ft_strlen(str) != map->w)
	{
		free(str);
		free(result);
		ft_error("the map isn't rectangle");
	}
}

void	getwidth(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
		i++;
	map->w = i;
}

void	putgnl(int fd, t_map *map)
{
	char	*str;
	char	*result;
	int		i;
	char	*tmp;

	setmap(map);
	result = ft_strdup("");
	i = 0;
	str = NULL;
	while (1)
	{
		tmp = result;
		str = get_next_line(fd);
		if (str != NULL)
			result = ft_strjoin(result, str);
		if (str == NULL)
			break ;
		free(tmp);
		free(str);
		i++;
	}
	map->h = i;
	map->map = ft_split(result, '\n');
	getwidth(map);
	free(result);
}
