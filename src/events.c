/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:09:19 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/22 20:09:32 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	destroy_sprites(t_game	*game)
{
	mlx_destroy_image(game->mlx, game->sprites.ground.img);
	mlx_destroy_image(game->mlx, game->sprites.exitclose.img);
	mlx_destroy_image(game->mlx, game->sprites.exitopen.img);
	mlx_destroy_image(game->mlx, game->sprites.btnup.img);
	mlx_destroy_image(game->mlx, game->sprites.btndown.img);
	mlx_destroy_image(game->mlx, game->sprites.cornerdownleft.img);
	mlx_destroy_image(game->mlx, game->sprites.cornerdownright.img);
	mlx_destroy_image(game->mlx, game->sprites.cornerupleft.img);
	mlx_destroy_image(game->mlx, game->sprites.cornerupright.img);
	mlx_destroy_image(game->mlx, game->sprites.player.img);
	mlx_destroy_image(game->mlx, game->sprites.playerdone.img);
	mlx_destroy_image(game->mlx, game->sprites.down.img);
	mlx_destroy_image(game->mlx, game->sprites.left.img);
	mlx_destroy_image(game->mlx, game->sprites.right.img);
	mlx_destroy_image(game->mlx, game->sprites.up.img);
	mlx_destroy_image(game->mlx, game->sprites.wall.img);
	mlx_destroy_image(game->mlx, game->sprites.walldown.img);
	mlx_destroy_image(game->mlx, game->sprites.wallleft.img);
	mlx_destroy_image(game->mlx, game->sprites.wallright.img);
	mlx_destroy_image(game->mlx, game->sprites.wallup.img);
}

int	close_win(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_window(game->mlx, game->win);
	destroy_sprites(game);
	ft_rwipe(game->alloc.map, 2);
	ft_rwipe(game->alloc.smap, 1);
	exit(0);
}

void	key_check(t_game *game, t_vec *player, t_sprites *sprites, int keycode)
{
	char		is_gameover;
	t_vec		*exit;

	exit = &game->exit;
	is_gameover = (player->y == exit->y && player->x == exit->x);
	if (keycode == KEY_ESC)
		close_win(game);
	else if ((keycode == KEY_W || keycode == KEY_UP) && !is_gameover)
		move_up(game, player, &sprites->up, KEY_UP);
	else if ((keycode == KEY_D || keycode == KEY_RIGHT) && !is_gameover)
		move_right(game, player, &sprites->right, KEY_RIGHT);
	else if ((keycode == KEY_S || keycode == KEY_DOWN) && !is_gameover)
		move_down(game, player, &sprites->down, KEY_DOWN);
	else if ((keycode == KEY_A || keycode == KEY_LEFT) && !is_gameover)
		move_left(game, player, &sprites->left, KEY_LEFT);
	else if (keycode == KEY_R)
	{
		reset_btns(game);
		put_map(game, sprites);
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
	key_check(game, player, sprites, keycode);
	is_gameover = (player->y == exit->y && player->x == exit->x);
	if (game->nbtns == 0 && !is_gameover)
		put_image(game, sprites->exitopen.img, exit->x, exit->y);
	if (is_gameover)
	{
		mlx_string_put(game->mlx, game->win, \
			((game->mapw * 32) / 2) - 104, \
			((game->maph * 32) / 2) - 12, 0x000000, "Press 'R' to resart !");
		mlx_string_put(game->mlx, game->win, \
			((game->mapw * 32) / 2) - 106, \
			((game->maph * 32) / 2) - 14, 0xffffff, "Press 'R' to resart !");
	}
	return (0);
}

void	reset_btns(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->alloc.map;
	game->nbtns = 0;
	game->nmoves = 0;
	i = -1;
	while (++i < game->maph)
	{
		j = -1;
		while (++j < game->mapw)
		{
			if (map[i][j] == 'c' || map[i][j] == 'C')
			{
				map[i][j] = 'C';
				game->nbtns++;
			}
			if (map[i][j] == 'P')
			{
				game->player.y = i;
				game->player.x = j;
			}
		}
	}
}
