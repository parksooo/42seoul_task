/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypressing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:49:10 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/02 17:16:21 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	find_moving_position(t_game *game, int keycode)
{
	if (keycode == KEY_W)
		game->map->pos[0]--;
	else if (keycode == KEY_S)
		game->map->pos[0]++;
	else if (keycode == KEY_A)
		game->map->pos[1]--;
	else if (keycode == KEY_D)
		game->map->pos[1]++;
	else
		return (FALSE);
	return (TRUE);
}

static int	victory(t_game *game)
{
	char	*tmp;

	game->move_cnt++;
	tmp = ft_itoa(game->move_cnt);
	ft_putendl_fd(tmp, 1);
	ft_putendl_fd("you're win!!", 1);
	free(tmp);
	exit(EXIT_SUCCESS);
}

static int	check_wall_exit(t_game *game, int bf_pos[])
{
	t_info	*map_info;

	map_info = game->map;
	if (map_info->map[map_info->pos[0]][map_info->pos[1]] == '1')
	{
		map_info->pos[0] = bf_pos[0];
		map_info->pos[1] = bf_pos[1];
		return (0);
	}
	if (map_info->map[map_info->pos[0]][map_info->pos[1]] == 'E'
		&& game->collect_cnt != map_info->collect)
	{
		map_info->pos[0] = bf_pos[0];
		map_info->pos[1] = bf_pos[1];
		return (0);
	}
	return (1);
}

static void	move_function(t_game *game, int *bf_pos, int *pos)
{
	char	**map;
	char	*tmp;

	map = game->map->map;
	game->move_cnt++;
	map[bf_pos[0]][bf_pos[1]] = '0';
	map[pos[0]][pos[1]] = 'P';
	tmp = ft_itoa(game->move_cnt);
	ft_putendl_fd(tmp, 1);
	free(tmp);
	chage_map(game);
}

int	keypress(int key_code, t_game *game)
{
	t_info	*map_info;
	int		bf_pos[2];

	map_info = game->map;
	bf_pos[0] = map_info->pos[0];
	bf_pos[1] = map_info->pos[1];
	if (key_code == KEY_ESC)
		exit_programm(game);
	if (!find_moving_position(game, key_code))
		return (0);
	if (!check_wall_exit(game, bf_pos))
		return (0);
	if (map_info->map[map_info->pos[0]][map_info->pos[1]] == 'C')
		game->collect_cnt++;
	if (map_info->map[map_info->pos[0]][map_info->pos[1]] == 'E'
		&& game->collect_cnt == map_info->collect)
		victory(game);
	else if (map_info->map[map_info->pos[0]][map_info->pos[1]] != '1' &&
		map_info->map[map_info->pos[0]][map_info->pos[1]] != 'E')
		move_function(game, bf_pos, map_info->pos);
	return (0);
}
