/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:09 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/27 16:00:21 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_info(t_info *map)
{
	map->collect = 0;
	map->exit = 0;
	map->point = 0;
	map->width = 0;
	map->height = 0;
	map->pos[0] = 0;
	map->pos[1] = 0;
}

void	init_image(void *mlx, t_img *img)
{
	int	w;
	int	h;

	img->player = mlx_xpm_file_to_image(mlx, "./xpmset/player.xpm", &w, &h);
	img->collect = mlx_xpm_file_to_image(mlx, "./xpmset/collect.xpm", &w, &h);
	img->eixt = mlx_xpm_file_to_image(mlx, "./xpmset/exit.xpm", &w, &h);
	img->empty = mlx_xpm_file_to_image(mlx, "./xpmset/empty.xpm", &w, &h);
	img->wall = mlx_xpm_file_to_image(mlx, "./xpmset/wall.xpm", &w, &h);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit(error("allocation failed"));
	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		exit(error("allocation failed"));
	game->map = (t_info *)malloc(sizeof(t_info));
	if (!game->map)
		exit(error("allocation failed"));
	init_info(game->map);
	game->move_cnt = 0;
	game->collect_cnt = 0;
	return (game);
}
