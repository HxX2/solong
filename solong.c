/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:09:04 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/26 22:39:49 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		throwerror("You need to provide one map");
	ft_memset(&game, 0, sizeof(t_game));
	game.nbtns = 0;
	game.nenemies = 0;
	game.nmoves = 2;
	game.mapfile = av[1];
	setmap(&game);
	checkmap(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.mapw * 32, game.maph * 32,
			"solong");
	set_sprites(&game);
	ft_printf("ne = %d\n", game.nenemies);
	game.enemies = ft_calloc(sizeof(t_vec) * game.nenemies);
	put_map(&game, &game.sprites);
	set_defaults(&game);
	mlx_hook(game.win, EVENT_CLOSE, 17, close_win, &game);
	game.isdead = 0;
	mlx_hook(game.win, EVENT_KEY_PRESS, 2, key_press, &game);
	srand(1337);
	mlx_loop_hook(game.mlx, move_enemies, &game);
	mlx_loop(game.mlx);
}

int	move_enemies(void *param)
{
	static int	count = 0;
	t_game		*game;
	char		**map;
	int			i;
	int			dir;

	if (count < 2000)
	{
		count++;
		return (0);
	}
	game = (t_game *)param;
	map = game->alloc.map;
	i = 0;
	while (i < game->nenemies)
	{
		game->isdead = (is_on_player(game, game->enemies[i].x,
					game->enemies[i].y) || is_on_enemy(game, game->player.x,
					game->player.y));
		if (game->isdead || (game->player.y == game->exit.y
				&& game->player.x == game->exit.x))
		{
			mlx_string_put(game->mlx, game->win, ((game->mapw * 32) / 2) - 104, \
					((game->maph * 32) / 2) - 12, 0x000000, \
					"Press 'R' to respawn !");
			mlx_string_put(game->mlx, game->win, ((game->mapw * 32) / 2) - 106, \
					((game->maph * 32) / 2) - 14, 0xffffff, \
					"Press 'R' to respawn !");
			return (0);
		}
		dir = rand() % 4;
		if (dir == 0)
			emove_up(game, &game->enemies[i], &game->bsprites.eup, KEY_UP);
		if (dir == 1)
			emove_down(game, &game->enemies[i], &game->bsprites.edown, \
			KEY_DOWN);
		if (dir == 2)
			emove_left(game, &game->enemies[i], &game->bsprites.eleft, \
			KEY_LEFT);
		if (dir == 3)
			emove_right(game, &game->enemies[i], &game->bsprites.eright, \
			KEY_RIGHT);
		i++;
	}
	if (game->nbtns == 0 && !(game->player.x == game->exit.x
			&& game->player.y == game->exit.y))
		put_image(game, game->sprites.exitopen.img, game->exit.x, game->exit.y);
	animation(game);
	count = 0;
	return (0);
}

void	animation(t_game *game)
{
	t_sprite	*sprites;
	static int	i = 0;

	sprites = ft_calloc(3 * sizeof(t_sprite));
	sprites[0] = game->sprites.exitclose;
	sprites[1] = game->bsprites.exitlight;
	if (game->nbtns != 0)
		put_image(game, sprites[i].img, game->exit.x, game->exit.y);
	i++;
	i %= 2;
}
