/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:09:04 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/28 16:44:08 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		throwerror("You need to provide one map");
	ft_memset(&game, 0, sizeof(t_game));
	game.nenemies = 0;
	game.mapfile = av[1];
	setmap(&game);
	checkmap(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.mapw * 32, game.maph * 32,
			"solong");
	set_sprites(&game);
	game.enemies = ft_calloc(sizeof(t_vec) * game.nenemies);
	game.alloc.animation = ft_calloc(2 * sizeof(t_sprite));
	put_map(&game, &game.sprites);
	set_defaults(&game);
	put_moves(&game, 0);
	mlx_hook(game.win, EVENT_CLOSE, 17, close_win, &game);
	game.isdead = 0;
	mlx_hook(game.win, EVENT_KEY_PRESS, 2, key_press, &game);
	srand(1337);
	mlx_loop_hook(game.mlx, move_enemies, &game);
	mlx_loop(game.mlx);
}

int	mlx_print(t_game *game)
{
	mlx_string_put(game->mlx, game->win, ((game->mapw * 32) / 2) - 104,
		((game->maph * 32) / 2) - 12, 0x000000, "Press 'R' to respawn !");
	mlx_string_put(game->mlx, game->win, ((game->mapw * 32) / 2) - 106,
		((game->maph * 32) / 2) - 14, 0xffffff, "Press 'R' to respawn !");
	return (0);
}
