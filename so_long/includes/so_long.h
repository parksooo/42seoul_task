/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:05:02 by suhwpark          #+#    #+#             */
/*   Updated: 2023/01/29 17:15:19 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//
# include <stdio.h>
//
# define TRUE 1
# define FALSE 0
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_PRESS 2
# define EXIT_BUTTON 17

typedef struct s_info
{
	char	**map;
	int		width;
	int		height;
	int		collect;
	int		exit;
	int		point;
	int		pos[2];
}	t_info;

typedef struct s_img
{
	void	*wall;
	void	*empty;
	void	*eixt;
	void	*player;
	void	*collect;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_info	*map;
	t_img	*img;
	int		move_cnt;
	int		collect_cnt;
}	t_game;

void	get_map(t_info *map_info, char *filename);
int		error(char *message);
t_game	*init_game(void);
void	init_image(void *mlx, t_img *img);
void	chage_map(t_game *game);
int		is_valid_map(t_info *map);
int		keypress(int key_code, t_game *game);
char	*get_next_line(int fd);
int		exit_programm(t_game *game);
int		bfs(t_info *info);
void	*safe_malloc(size_t	size);
#endif