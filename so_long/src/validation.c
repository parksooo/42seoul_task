/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:50:23 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/28 21:12:52 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	proper_info(t_info *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (map->exit != 1 || map->point != 1)
		return (FALSE);
	if (map->collect < 1)
		return (FALSE);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
					&& map->map[i][j] != 'P' && map->map[i][j] != 'E'
						&& map->map[i][j] != 'C')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	rectangular_map(t_info *map)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (len != ft_strlen(map->map[i]))
			return (FALSE);
		i++;
	}
	map->width = len;
	return (TRUE);
}

static int	surround_wall(t_info *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		if (i == 0 || i == map->height - 1)
		{
			j = 0;
			while (map->map[i][j])
			{
				if (map->map[i][j] != '1')
					return (FALSE);
				j++;
			}
		}
		else
		{
			if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	vaild_path(t_info *map)
{
	if (!bfs(map))
		return (FALSE);
	return (TRUE);
}

int	is_valid_map(t_info *map)
{
	if (!proper_info(map))
		return (FALSE);
	if (!rectangular_map(map))
		return (FALSE);
	if (!surround_wall(map))
		return (FALSE);
	if (!vaild_path(map))
		return (FALSE);
	return (TRUE);
}
