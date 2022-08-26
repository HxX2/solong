/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:31:15 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/26 22:41:50 by zlafou           ###   ########.fr       */
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
			put_moves(game, ++game->nmoves);
	}
	else
		put_image(game, sprite->img, player->x, player->y);
}

void	is_btndown(t_game *game, t_vec *player, t_sprite *sprite, int key)
{
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
		put_moves(game, ++game->nmoves);
}

void	is_btnup(t_game *game, t_vec *player, t_sprite *sprite, int key)
{
	if (game->nbtns != 0)
		game->nbtns -= 1;
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
		put_moves(game, ++game->nmoves);
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
		put_moves(game, ++game->nmoves);
}

void	is_enemy(t_game *game, t_vec *player, int key)
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
	put_image(game, game->bsprites.enemy.img, player->x, player->y);
	put_image(game, game->bsprites.pdead.img, player->x, player->y);
	if (player->etype == 'P')
		put_moves(game, ++game->nmoves);
}

void	put_moves(t_game *game, int moves)
{
	ft_printf("%d\n", game->nmoves);
	put_image(game, game->bsprites.mask.img, 2, 0);
	put_image(game, game->bsprites.mask.img, 3, 0);
	put_image(game, game->bsprites.mask.img, 4, 0);
	put_image(game, game->bsprites.mask.img, 5, 0);
	mlx_string_put(game->mlx, game->win, 79, \
		-1, 0xffffff, ft_strjoin("moves: ", ft_itoa(moves)));
}
