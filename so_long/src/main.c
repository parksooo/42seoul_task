/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:01:31 by suhwpark          #+#    #+#             */
/*   Updated: 2023/02/02 17:16:14 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_programm(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

static int	argument_check(int argc, char *filename)
{
	int	len;

	if (argc != 2)
		return (FALSE);
	len = ft_strlen(filename);
	if (len < 5)
		return (FALSE);
	if (ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!argument_check(argc, argv[1]))
		exit(error("invalided arguments"));
	game = init_game();
	get_map(game->map, argv[1]);
	if (!is_valid_map(game->map))
		exit(error("invalided map"));
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map->width * 64,
			game->map->height * 64, "./so_long");
	init_image(game->mlx, game->img);
	chage_map(game);
	mlx_hook(game->window, KEY_PRESS, 0, keypress, game);
	mlx_hook(game->window, EXIT_BUTTON, 0, exit_programm, game);
	mlx_loop(game->mlx);
}
