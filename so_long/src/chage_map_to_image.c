/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chage_map_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:54:11 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/27 15:54:53 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	select_image(t_game *game, char stuff, int i, int j)
{
	if (stuff == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->eixt, j * 64, i * 64);
	else if (stuff == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->player, j * 64, i * 64);
	else if (stuff == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->collect, j * 64, i * 64);
	else if (stuff == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->empty, j * 64, i * 64);
	else if (stuff == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img->wall, j * 64, i * 64);
}

void	chage_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			select_image(game, game->map->map[i][j], i, j);
			j++;
		}
		i++;
	}
}
