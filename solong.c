/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:09:04 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/29 22:35:15 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		throwerror("You need to provide one map");
	ft_memset(&game, 0, sizeof(t_game));
	game.mapfile = av[1];
	setmap(&game);
	checkmap(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.mapw * 32, game.maph * 32,
			"solong");
	set_sprites(&game);
	put_map(&game, &game.sprites);
	set_defaults(&game);
	ft_printf("%d\n", 0);
	mlx_hook(game.win, EVENT_CLOSE, 17, close_win, &game);
	mlx_hook(game.win, EVENT_KEY_PRESS, 2, key_press, &game);
	mlx_loop_hook(game.mlx, is_gameover, &game);
	mlx_loop(game.mlx);
}

int	mlx_print(t_game *game)
{
	mlx_string_put(game->mlx, game->win, ((game->mapw * 32) / 2) - 104,
		((game->maph * 32) / 2) - 12, 0x000000, "Press 'R' to restart !");
	mlx_string_put(game->mlx, game->win, ((game->mapw * 32) / 2) - 106,
		((game->maph * 32) / 2) - 14, 0xffffff, "Press 'R' to restart !");
	return (0);
}

int	is_gameover(t_game *game)
{
	int	onexit;

	onexit = (game->player.y == game->exit.y && game->player.x == game->exit.x);
	if (game->nbtns == 0 && !onexit)
		put_image(game, game->sprites.exitopen.img, game->exit.x, game->exit.y);
	if (onexit)
		return (mlx_print(game));
	return (0);
}
