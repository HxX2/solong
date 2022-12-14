/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:31:15 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/29 22:08:00 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	is_exit(t_game *game, t_vec *player, t_sprite *sprite, int key)
{
	if (game->alloc.map[player->y][player->x] == 'c')
		put_image(game, game->sprites.btndown.img, player->x, player->y);
	else
		put_image(game, game->sprites.ground.img, player->x, player->y);
	if (game->nbtns == 0)
	{
		if (key == KEY_UP)
			player->y -= 1;
		else if (key == KEY_DOWN)
			player->y += 1;
		else if (key == KEY_LEFT)
			player->x -= 1;
		else if (key == KEY_RIGHT)
			player->x += 1;
		put_image(game, game->sprites.exitopen.img, player->x, player->y);
		put_image(game, game->sprites.playerdone.img, player->x, player->y);
		if (player->etype == 'P')
			ft_printf("%d\n", ++game->nmoves);
	}
	else
		put_image(game, sprite->img, player->x, player->y);
}

void	is_btndown(t_game *game, t_vec *player, t_sprite *sprite, int key)
{
	if (game->alloc.map[player->y][player->x] == 'c')
		put_image(game, game->sprites.btndown.img, player->x, player->y);
	else
		put_image(game, game->sprites.ground.img, player->x, player->y);
	if (key == KEY_UP)
		player->y -= 1;
	else if (key == KEY_DOWN)
		player->y += 1;
	else if (key == KEY_LEFT)
		player->x -= 1;
	else if (key == KEY_RIGHT)
		player->x += 1;
	put_image(game, game->sprites.btndown.img, player->x, player->y);
	put_image(game, sprite->img, player->x, player->y);
	if (player->etype == 'P')
		ft_printf("%d\n", ++game->nmoves);
}

void	is_btnup(t_game *game, t_vec *player, t_sprite *sprite, int key)
{
	if (game->nbtns != 0)
		game->nbtns -= 1;
	if (game->alloc.map[player->y][player->x] == 'c')
		put_image(game, game->sprites.btndown.img, player->x, player->y);
	else
		put_image(game, game->sprites.ground.img, player->x, player->y);
	if (key == KEY_UP)
		player->y -= 1;
	else if (key == KEY_DOWN)
		player->y += 1;
	else if (key == KEY_LEFT)
		player->x -= 1;
	else if (key == KEY_RIGHT)
		player->x += 1;
	put_image(game, game->sprites.btndown.img, player->x, player->y);
	put_image(game, sprite->img, player->x, player->y);
	game->alloc.map[player->y][player->x] = 'c';
	if (player->etype == 'P')
		ft_printf("%d\n", ++game->nmoves);
}

void	is_ground(t_game *game, t_vec *player, t_sprite *sprite, int key)
{
	if (game->alloc.map[player->y][player->x] == 'c')
		put_image(game, game->sprites.btndown.img, player->x, player->y);
	else
		put_image(game, game->sprites.ground.img, player->x, player->y);
	if (key == KEY_UP)
		player->y -= 1;
	else if (key == KEY_DOWN)
		player->y += 1;
	else if (key == KEY_LEFT)
		player->x -= 1;
	else if (key == KEY_RIGHT)
		player->x += 1;
	put_image(game, game->sprites.ground.img, player->x, player->y);
	put_image(game, sprite->img, player->x, player->y);
	if (player->etype == 'P')
		ft_printf("%d\n", ++game->nmoves);
}
