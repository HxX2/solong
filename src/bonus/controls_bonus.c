/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:08:52 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/30 20:03:54 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../solong_bonus.h"

void	move_up(t_game *game, t_vec *player, t_sprite *sprite, int key)
{
	if (game->alloc.map[player->y - 1][player->x] == 'E')
		is_exit(game, player, sprite, key);
	else if (is_on_enemy(game, player->x, player->y - 1))
		is_enemy(game, player, key);
	else if (game->alloc.map[player->y - 1][player->x] == 'c')
		is_btndown(game, player, sprite, key);
	else if (game->alloc.map[player->y - 1][player->x] == 'C')
		is_btnup(game, player, sprite, key);
	else if (game->alloc.map[player->y - 1][player->x] != '1')
		is_ground(game, player, sprite, key);
	else
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
}

void	move_down(t_game	*game, t_vec	*player, t_sprite *sprite, int key)
{
	if (game->alloc.map[player->y + 1][player->x] == 'E')
		is_exit(game, player, sprite, key);
	else if (is_on_enemy(game, player->x, player->y + 1))
		is_enemy(game, player, key);
	else if (game->alloc.map[player->y + 1][player->x] == 'c')
		is_btndown(game, player, sprite, key);
	else if (game->alloc.map[player->y + 1][player->x] == 'C' )
		is_btnup(game, player, sprite, key);
	else if (game->alloc.map[player->y + 1][player->x] != '1')
		is_ground(game, player, sprite, key);
	else
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
}

void	move_left(t_game	*game, t_vec	*player, t_sprite *sprite, int key)
{
	if (game->alloc.map[player->y][player->x - 1] == 'E')
		is_exit(game, player, sprite, key);
	else if (is_on_enemy(game, player->x - 1, player->y))
		is_enemy(game, player, key);
	else if (game->alloc.map[player->y][player->x - 1] == 'c')
		is_btndown(game, player, sprite, key);
	else if (game->alloc.map[player->y][player->x - 1] == 'C')
		is_btnup(game, player, sprite, key);
	else if (game->alloc.map[player->y][player->x - 1] != '1')
		is_ground(game, player, sprite, key);
	else
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
}

void	move_right(t_game *game, t_vec *player, t_sprite *sprite, int key)
{
	if (game->alloc.map[player->y][player->x + 1] == 'E')
		is_exit(game, player, sprite, key);
	else if (is_on_enemy(game, player->x + 1, player->y))
		is_enemy(game, player, key);
	else if (game->alloc.map[player->y][player->x + 1] == 'c')
		is_btndown(game, player, sprite, key);
	else if (game->alloc.map[player->y][player->x + 1] == 'C')
		is_btnup(game, player, sprite, key);
	else if (game->alloc.map[player->y][player->x + 1] != '1')
		is_ground(game, player, sprite, key);
	else
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
}

int	is_on_enemy(t_game *game, int px, int py)
{
	int		i;
	int		ex;
	int		ey;

	i = 0;
	while (i < game->nenemies)
	{
		ex = game->enemies[i].x;
		ey = game->enemies[i].y;
		if (py == ey && px == ex)
			return (1);
		i++;
	}
	return (0);
}
