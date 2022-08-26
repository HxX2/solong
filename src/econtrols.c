/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   econtrols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:08:52 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/25 18:41:48 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	emove_up(t_game *game, t_vec *enemy, t_sprite *sprite, int key)
{
	if (is_on_player(game, enemy->x, enemy->y - 1))
		is_enemy(game, enemy, key);
	else if (game->alloc.map[enemy->y - 1][enemy->x] == 'c')
		is_btndown(game, enemy, sprite, key);
	else if (game->alloc.map[enemy->y - 1][enemy->x] == '0')
		is_ground(game, enemy, sprite, key);
	else
	{
		if (game->alloc.map[enemy->y][enemy->x] == 'c' )
			put_image(game, game->sprites.btndown.img, enemy->x, enemy->y);
		else
			put_image(game, game->sprites.ground.img, enemy->x, enemy->y);
		put_image(game, sprite->img, enemy->x, enemy->y);
	}
}

void	emove_down(t_game *game, t_vec *enemy, t_sprite *sprite, int key)
{
	if (is_on_player(game, enemy->x, enemy->y + 1))
		is_enemy(game, enemy, key);
	else if (game->alloc.map[enemy->y + 1][enemy->x] == 'c')
		is_btndown(game, enemy, sprite, key);
	else if (game->alloc.map[enemy->y + 1][enemy->x] == '0')
		is_ground(game, enemy, sprite, key);
	else
	{
		if (game->alloc.map[enemy->y][enemy->x] == 'c' )
			put_image(game, game->sprites.btndown.img, enemy->x, enemy->y);
		else
			put_image(game, game->sprites.ground.img, enemy->x, enemy->y);
		put_image(game, sprite->img, enemy->x, enemy->y);
	}
}

void	emove_left(t_game *game, t_vec	*enemy, t_sprite *sprite, int key)
{
	if (is_on_player(game, enemy->x - 1, enemy->y))
		is_enemy(game, enemy, key);
	else if (game->alloc.map[enemy->y][enemy->x - 1] == 'c')
		is_btndown(game, enemy, sprite, key);
	else if (game->alloc.map[enemy->y][enemy->x - 1] == '0')
		is_ground(game, enemy, sprite, key);
	else
	{
		if (game->alloc.map[enemy->y][enemy->x] == 'c' )
			put_image(game, game->sprites.btndown.img, enemy->x, enemy->y);
		else
			put_image(game, game->sprites.ground.img, enemy->x, enemy->y);
		put_image(game, sprite->img, enemy->x, enemy->y);
	}
}

void	emove_right(t_game *game, t_vec *enemy, t_sprite *sprite, int key)
{
	if (is_on_player(game, enemy->x + 1, enemy->y))
		is_enemy(game, enemy, key);
	else if (game->alloc.map[enemy->y][enemy->x + 1] == 'c')
		is_btndown(game, enemy, sprite, key);
	else if (game->alloc.map[enemy->y][enemy->x + 1] == '0')
		is_ground(game, enemy, sprite, key);
	else
	{
		if (game->alloc.map[enemy->y][enemy->x] == 'c' )
			put_image(game, game->sprites.btndown.img, enemy->x, enemy->y);
		else
			put_image(game, game->sprites.ground.img, enemy->x, enemy->y);
		put_image(game, sprite->img, enemy->x, enemy->y);
	}
}

int	is_on_player(t_game *game, int ex, int ey)
{
	int		px;
	int		py;

	px = game->player.x;
	py = game->player.y;
	if (py == ey && px == ex)
		return (1);
	return (0);
}
