/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:09:19 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/28 16:45:52 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	close_win(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_window(game->mlx, game->win);
	destroy_sprites(game);
	ft_rwipe(game->alloc.map, 2);
	ft_rwipe(game->alloc.smap, 1);
	ft_rwipe(game->enemies, 1);
	ft_rwipe(game->alloc.animation, 1);
	exit(0);
}

void	key_check(t_game *game, t_vec *player, t_sprites *sprites, int keycode)
{
	int			i;
	t_vec		*enemies;

	enemies = game->enemies;
	if ((keycode == KEY_W || keycode == KEY_UP))
		move_up(game, player, &sprites->up, KEY_UP);
	else if ((keycode == KEY_D || keycode == KEY_RIGHT))
		move_right(game, player, &sprites->right, KEY_RIGHT);
	else if ((keycode == KEY_S || keycode == KEY_DOWN))
		move_down(game, player, &sprites->down, KEY_DOWN);
	else if ((keycode == KEY_A || keycode == KEY_LEFT))
		move_left(game, player, &sprites->left, KEY_LEFT);
	i = 0;
	while (i < game->nenemies)
	{
		game->isdead = (is_on_player(game, enemies[i].x, game->enemies[i].y) \
				|| is_on_enemy(game, game->player.x, game->player.y));
		i++;
	}
}

int	key_press(int keycode, void *param)
{
	t_game		*game;
	t_sprites	*sprites;
	t_vec		*player;
	t_vec		*exit;
	char		is_gameover;

	game = (t_game *)param;
	sprites = &game->sprites;
	player = &game->player;
	exit = &game->exit;
	is_gameover = (player->y == exit->y && player->x == exit->x);
	if (keycode == KEY_R)
	{
		set_defaults(game);
		put_map(game, sprites);
		put_moves(game, 0);
	}
	if (keycode == KEY_ESC)
		close_win(game);
	if (is_gameover || game->isdead)
		return (0);
	key_check(game, player, sprites, keycode);
	return (0);
}

void	set_defaults(t_game *game)
{
	int		i;
	int		j;
	int		k;

	game->nbtns = 0;
	game->nmoves = 0;
	i = -1;
	k = 0;
	while (++i < game->maph)
	{
		j = -1;
		while (++j < game->mapw)
			reset_enteties(game, i, j, &k);
	}
}

void	reset_enteties(t_game *game, int i, int j, int *k)
{
	char	**map;

	map = game->alloc.map;
	if (map[i][j] == 'c' || map[i][j] == 'C')
	{
		map[i][j] = 'C';
		game->nbtns++;
	}
	if (map[i][j] == 'P')
	{
		game->player.y = i;
		game->player.x = j;
		game->player.etype = 'P';
	}
	if (map[i][j] == 'B')
	{
		game->enemies[*k].y = i;
		game->enemies[*k].x = j;
		game->enemies[(*k)++].etype = 'B';
	}
}
