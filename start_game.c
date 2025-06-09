/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:43:13 by etamazya          #+#    #+#             */
/*   Updated: 2025/06/09 12:05:05 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int key, t_game *game)
{
	// printf("Key pressed: %d\n", key);
	if (key == ESC)
		exit_game(game, -1);
	else if (key == W || key == UP)
		move_up(game);
	else if (key == S || key == DOWN)
		move_down(game);
	else if (key == A || key == LEFT)
		move_left(game);
	else if (key == D || key == RIGHT)
		move_right(game);
	return (0);
}

void	run_game(t_map *map)
{
	t_game	game;

	game.map = *map;
	game.img.mlx = mlx_init();
	game.img.win = mlx_new_window(game.img.mlx, game.map.cols * 60,
			game.map.raws * 60, "game_system");
	retype_img(&game);
	game.img.p = game.img.plr;
	game.img.e = game.img.c_exit;
	game.steps = 0;
	game.anim = anim_coin(&game);
	init_map(&game, game.anim);
	// Linux
	mlx_hook(game.img.win, 2, 1L << 0, press_key, &game);
	// MacOS
	// mlx_hook(game.img.win, 2, 0, press_key, &game);
	mlx_loop_hook(game.img.mlx, &frame, &game);
	// Linux
	mlx_hook(game.img.win, 17, 0L, press_exit, &game);
	// MacOS
	// mlx_hook(game.img.win, 17, 0, &press_exit, &game);
	mlx_loop(game.img.mlx);
}
// make null plr | l_plr | c_exit | o_exit
void	retype_img(t_game *game)
{
	game->width = SIZE;
	game->height = SIZE;
	game->img.coin = mlx_xpm_file_to_image(game->img.mlx,
			"textures/titan.xpm", &game->width, &game->height);
	game->img.rcoin = mlx_xpm_file_to_image(game->img.mlx,
			"textures/r_titan.xpm", &game->width, &game->height);
	game->img.plr = mlx_xpm_file_to_image(game->img.mlx,
			"textures/player.xpm", &game->width, &game->height);
	game->img.l_pr = mlx_xpm_file_to_image(game->img.mlx,
			"textures/l_player.xpm", &game->width, &game->height);
	game->img.ground = mlx_xpm_file_to_image(game->img.mlx,
			"textures/ground.xpm", &game->width, &game->height);
	game->img.walls = mlx_xpm_file_to_image(game->img.mlx,
			"textures/wall.xpm", &game->width, &game->height);
	game->img.c_exit = mlx_xpm_file_to_image(game->img.mlx,
			"textures/close_e.xpm", &game->width, &game->height);
	game->img.o_exit = mlx_xpm_file_to_image(game->img.mlx,
			"textures/open_e.xpm", &game->width, &game->height);
	game->img.monster = mlx_xpm_file_to_image(game->img.mlx,
			"textures/monster.xpm", &game->width, &game->height);
}

void	change_point(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	mlx_string_put(game->img.mlx, game->img.win, (game->map.cols - 2) * SIZE,
		0, 0x0, str);
	free(str);
}
