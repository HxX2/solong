/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:11:11 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/21 18:07:06 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "src/printf/ft_printf.h"

# define EVENT_CLOSE 17
# define EVENT_KEY_PRESS 2
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

typedef struct s_exit
{
	int		x;
	int		y;
}			t_exit;

typedef struct s_alloc
{
	char	**map;
	char	*smap;
}		t_alloc;

typedef struct s_sprite
{
	void	*img;
	int		h;
	int		w;
}			t_sprite;

typedef struct s_sprites
{
	t_sprite	ground;
	t_sprite	exitclose;
	t_sprite	exitopen;
	t_sprite	btnup;
	t_sprite	btndown;
	t_sprite	cornerdownleft;
	t_sprite	cornerdownright;
	t_sprite	cornerupleft;
	t_sprite	cornerupright;
	t_sprite	player;
	t_sprite	playerdone;
	t_sprite	down;
	t_sprite	left;
	t_sprite	right;
	t_sprite	up;
	t_sprite	wall;
	t_sprite	walldown;
	t_sprite	wallleft;
	t_sprite	wallright;
	t_sprite	wallup;
}		t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*mapfile;
	int			mapwidth;
	int			mapheight;
	int			nbtns;
	t_sprites	sprites;
	t_player	player;
	t_exit		exit;
	t_alloc		alloc;
}		t_game;

void	check_rectangular_walls(t_game	*game);
void	setmap(t_game	*game);
void	check_keys(t_game	*game);
void	set_sprites(t_game	*game);
void	put_walls(t_game *game, t_sprites *sprites, int x, int y);
void	put_map(t_game *game, t_sprites *sprites);
void	put_image(t_game *game, void	*img, int x, int y);

int		close_win(void *param);
int		key_press(int keycode, void *param);

char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	throwerror(char *msg);
void	*ft_calloc(size_t n);

void ft_sleep(void);
int	loop_hook(void *param);

#endif