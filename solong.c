/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:09:04 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/22 21:36:46 by zlafou           ###   ########.fr       */
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
	game.nmoves = 1;
	game.mapfile = av[1];
	setmap(&game);
	check_keys(&game);
	check_rectangular_walls(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.mapw * 32, \
		game.maph * 32, "solong");
	set_sprites(&game);
	put_map(&game, &game.sprites);
	mlx_hook(game.win, EVENT_CLOSE, 17, close_win, &game);
	mlx_hook(game.win, EVENT_KEY_PRESS, 2, key_press, &game);
	mlx_loop(game.mlx);
}
