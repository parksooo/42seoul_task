/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:41:31 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/29 15:13:06 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_map_column_count(char *map)
{
	int		cnt;
	size_t	i;

	cnt = 0;
	i = -1;
	while (++i < ft_strlen(map))
	{
		if (map[i] == '\n')
			cnt++;
	}
	return (cnt + 1);
}

static char	**get_real_map(char *map)
{
	char	**real_map;

	real_map = ft_split(map, '\n');
	if (!real_map)
		exit(error("allocation failed"));
	return (real_map);
}

static void	get_map_info(t_info *map_info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == 'P')
			{
				map_info->point++;
				map_info->pos[0] = i;
				map_info->pos[1] = j;
			}
			if (map_info->map[i][j] == 'E')
				map_info->exit++;
			if (map_info->map[i][j] == 'C')
				map_info->collect++;
			j++;
		}
		i++;
	}
}

void	get_map(t_info *map_info, char *filename)
{
	char	*temp;
	char	*line;
	char	*join;
	int		fd;

	fd = open(filename, O_RDONLY);
	join = ft_strdup("");
	if (!join)
		exit(error("allocated failed"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = join;
		join = ft_strjoin(join, line);
		if (!join)
			exit(error("allocated failed"));
		free(temp);
		free(line);
	}
	map_info->height = get_map_column_count(join);
	map_info->map = get_real_map(join);
	free(join);
	get_map_info(map_info);
}
