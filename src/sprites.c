/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:55:20 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/22 18:37:57 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	set_walls(t_game *game)
{
	game->sprites.cornerdownleft.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/cdl.xpm", \
		&game->sprites.cornerdownleft.w, &game->sprites.cornerdownleft.h);
	game->sprites.cornerdownright.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/cdr.xpm", \
		&game->sprites.cornerdownright.w, &game->sprites.cornerdownright.h);
	game->sprites.cornerupleft.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/cul.xpm", \
		&game->sprites.cornerupleft.w, &game->sprites.cornerupleft.h);
	game->sprites.cornerupright.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/cur.xpm", \
		&game->sprites.cornerupright.w, &game->sprites.cornerupright.h);
	game->sprites.walldown.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/walldown.xpm", \
		&game->sprites.walldown.w, &game->sprites.walldown.h);
	game->sprites.wallup.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/wallup.xpm", \
		&game->sprites.wallup.w, &game->sprites.wallup.h);
	game->sprites.wallright.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/wallright.xpm", \
		&game->sprites.wallright.w, &game->sprites.wallright.h);
	game->sprites.wallleft.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/wallleft.xpm", \
		&game->sprites.wallleft.w, &game->sprites.wallleft.h);
}

static void	set_player(t_game *game)
{
	game->sprites.down.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/down.xpm", \
		&game->sprites.down.w, &game->sprites.down.h);
	game->sprites.up.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/up.xpm", \
		&game->sprites.up.w, &game->sprites.up.h);
	game->sprites.right.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/right.xpm", \
		&game->sprites.right.w, &game->sprites.right.h);
	game->sprites.left.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/left.xpm", \
		&game->sprites.left.w, &game->sprites.left.h);
	game->sprites.player.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/player.xpm", \
		&game->sprites.player.w, &game->sprites.player.h);
	game->sprites.playerdone.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/playerdone.xpm", \
		&game->sprites.playerdone.w, &game->sprites.playerdone.h);
}

void	set_sprites(t_game *game)
{
	set_player(game);
	set_walls(game);
	game->sprites.ground.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/ground.xpm", \
		&game->sprites.ground.w, &game->sprites.ground.h);
	game->sprites.wall.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/wall.xpm", \
		&game->sprites.wall.w, &game->sprites.wall.h);
	game->sprites.exitclose.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/exitclose.xpm", \
		&game->sprites.exitclose.w, &game->sprites.exitclose.h);
	game->sprites.exitopen.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/exitopen.xpm", \
		&game->sprites.exitopen.w, &game->sprites.exitopen.h);
	game->sprites.btnup.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/btnup.xpm", \
		&game->sprites.btnup.w, &game->sprites.btnup.h);
	game->sprites.btndown.img = \
		mlx_xpm_file_to_image(game->mlx, "assets/sprites/xpm/btndown.xpm", \
		&game->sprites.btndown.w, &game->sprites.btndown.h);
}
