/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:10:22 by etamazya          #+#    #+#             */
/*   Updated: 2025/06/09 13:00:09 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"


# define SIZE 60

#ifdef __linux__
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define ESC 65307
#else
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
#endif


typedef struct s_img
{
	void	*coin;
	void	*rcoin;
	void	*e;
	void	*c_exit;
	void	*o_exit;
	void	*p;
	void	*plr;
	void	*l_pr;
	void	*ground;
	void	*walls;
	void	*monster;
	void	*mlx;
	void	*win;
}	t_img;

typedef struct s_plr
{
	int	pos_x;
	int	pos_y;
}	t_plr;

typedef struct s_map
{
	char		**data;
	t_plr	plr;
	int			raws; // N
	int			cols; //M
	int			coins;
}	t_map;

typedef struct s_game
{
	t_map	map;
	t_img	img;
	int		width;
	int		height;
	int		steps;
	void	*anim;
}	t_game;

void		is_fd_valid(char *argv);
int			ft_strncmp(const char *s1, const char *s2, int limit);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char *s1, char *s2);
char		**fd_parse(int fd);
void		check_newline(char *join);
char		*ft_strtrim2(char *s1, char *set);
char		*check_newline2(char *join);
void		check_whitespaces(char **res);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, size_t start, size_t len);
char		*ft_itoa(int n);
char		*ft_strdup_1(const char *s1);
int			count_len(int n);
char		**ft_pars(int fd);
void		is_map_valid(t_map *map);
void		check_chars(t_map *map);
void		check_walls(t_map *map);
void		check_sidewalls(t_map *map);
void		char_existence(t_map **map, char c);
void		plr_existence(t_map *map);
void		flood(t_map *map);
char		**map_dup(t_map *map, int i, int j);
char		*real_strdup(const char *s1);
void		fill(char **tab, t_map *map, t_plr current, char target);
void		clean_str(char **arr, int i);
void		passable_path(char **path);
void		run_game(t_map *map);
void		retype_img(t_game *game);
int			press_key(int key, t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		*anim_coin(t_game *game);
int			press_exit(t_game *game);
void		change_point(t_game *game);
int			init_map(t_game *game, void *anim);
void		init_map_pt2(t_game *game, void *anim, int i, int j);
void		init_map_pt3(t_game *game, int i, int j);
void		exit_game(t_game *game, int out);
int			frame(t_game *game);
// void is_only_wspace();

#endif
