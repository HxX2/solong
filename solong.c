/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:09:04 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/21 18:29:04 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int	ac,char	**av)
{

	t_game	game;

	if (ac != 2)
		throwerror("You need to provide one map");
	ft_memset(&game, 0, sizeof(t_game));
	game.nbtns = 0;
	game.mapfile = av[1];
	setmap(&game);
	check_keys(&game);
	check_rectangular_walls(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.mapwidth * 32, game.mapheight * 32, "win");
	set_sprites(&game);
	put_map(&game, &game.sprites);
	mlx_hook(game.win, EVENT_CLOSE, 17, close_win, &game);
	mlx_hook(game.win, EVENT_KEY_PRESS, 2, key_press, &game);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
}

int	loop_hook(void *param)
{
	t_game		*game;
	t_sprites 	*sprites;
	t_player	*player;
	t_exit	*exit;

	game = (t_game *)param;
	sprites = &game->sprites;
	player = &game->player;
	exit = &game->exit;
	if (game->nbtns == 0 && !(player->y == exit->y && player->x == exit->x))
		put_image(game, sprites->exitopen.img, exit->x, exit->y);
	if (game->exit.x == game->player.x && game->exit.y == game->player.y)
	{
		ft_sleep();
		close_win(param);
	}
	return (0);
}