/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:09:19 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/21 21:15:39 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	close_win(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_sleep();
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	move_player_up(t_game *game, t_player *player, t_sprite *sprite)
{
	if (game->alloc.map[player->y - 1][player->x] == 'E')
	{
		if (game->alloc.map[player->y][player->x] == 'C' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		if (game->nbtns == 0)
		{
			player->y -= 1;
			put_image(game, game->sprites.exitopen.img, player->x, player->y);
			put_image(game, game->sprites.playerdone.img, player->x, player->y);
		}
		else
			put_image(game, sprite->img, player->x, player->y);
	}
	else if (game->alloc.map[player->y - 1][player->x] == 'c')
	{
		put_image(game, game->sprites.ground.img, player->x, player->y);
		player->y -= 1;
		put_image(game, game->sprites.btndown.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
	else if (game->alloc.map[player->y - 1][player->x] == 'C')
	{
		if (game->nbtns != 0)
			game->nbtns -= 1;
		put_image(game, game->sprites.ground.img, player->x, player->y);
		player->y -= 1;
		put_image(game, game->sprites.btndown.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
		game->alloc.map[player->y][player->x] = 'c';
	}
	else if (game->alloc.map[player->y - 1][player->x] != '1')
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		player->y -= 1;
		put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
	else
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
}

void	move_player_down(t_game	*game, t_player	*player, t_sprite *sprite)
{
	if (game->alloc.map[player->y + 1][player->x] == 'E')
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		if (game->nbtns == 0)
		{
			player->y += 1;
			put_image(game, game->sprites.exitopen.img, player->x, player->y);
			put_image(game, game->sprites.playerdone.img, player->x, player->y);
		}
		else
			put_image(game, sprite->img, player->x, player->y);
	}
	else if (game->alloc.map[player->y + 1][player->x] == 'c')
	{
		put_image(game, game->sprites.ground.img, player->x, player->y);
		player->y += 1;
		put_image(game, game->sprites.btndown.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
	else if (game->alloc.map[player->y + 1][player->x] == 'C' )
	{
		if (game->nbtns != 0)
			game->nbtns -= 1;
		put_image(game, game->sprites.ground.img, player->x, player->y);
		player->y += 1;
		put_image(game, game->sprites.btndown.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
		game->alloc.map[player->y][player->x] = 'c';
	}
	else if (game->alloc.map[player->y + 1][player->x] != '1')
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		player->y += 1;
		put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
	else
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
}

void	move_player_left(t_game	*game, t_player	*player, t_sprite *sprite)
{
	if (game->alloc.map[player->y][player->x - 1] == 'E')
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		if (game->nbtns == 0)
		{
			player->x -= 1;
			put_image(game, game->sprites.exitopen.img, player->x, player->y);
			put_image(game, game->sprites.playerdone.img, player->x, player->y);
		}
		else
			put_image(game, sprite->img, player->x, player->y);
	}
	else if (game->alloc.map[player->y][player->x - 1] == 'c')
	{
		put_image(game, game->sprites.ground.img, player->x, player->y);
		player->x -= 1;
		put_image(game, game->sprites.btndown.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
	else if (game->alloc.map[player->y][player->x - 1] == 'C')
	{
		if (game->nbtns != 0)
			game->nbtns -= 1;
		put_image(game, game->sprites.ground.img, player->x, player->y);
		player->x -= 1;
		put_image(game, game->sprites.btndown.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
		game->alloc.map[player->y][player->x] = 'c';
	}
	else if (game->alloc.map[player->y][player->x - 1] != '1')
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		player->x -= 1;
		put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
	else
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
}

void	move_player_right(t_game *game, t_player *player, t_sprite *sprite)
{
	if (game->alloc.map[player->y][player->x + 1] == 'E')
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		if (game->nbtns == 0)
		{
			player->x += 1;
			put_image(game, game->sprites.exitopen.img, player->x, player->y);
			put_image(game, game->sprites.playerdone.img, player->x, player->y);
		}
		else
			put_image(game, sprite->img, player->x, player->y);
	}
	else if (game->alloc.map[player->y][player->x + 1] == 'c')
	{
		put_image(game, game->sprites.ground.img, player->x, player->y);
		player->x += 1;
		put_image(game, game->sprites.btndown.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
	else if (game->alloc.map[player->y][player->x + 1] == 'C')
	{
		if (game->nbtns != 0)
			game->nbtns -= 1;
		put_image(game, game->sprites.ground.img, player->x, player->y);
		player->x += 1;
		put_image(game, game->sprites.btndown.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
		game->alloc.map[player->y][player->x] = 'c';
	}
	else if (game->alloc.map[player->y][player->x + 1] != '1')
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		player->x += 1;
		put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
	else
	{
		if (game->alloc.map[player->y][player->x] == 'c' )
			put_image(game, game->sprites.btndown.img, player->x, player->y);
		else
			put_image(game, game->sprites.ground.img, player->x, player->y);
		put_image(game, sprite->img, player->x, player->y);
	}
}

int	key_press(int keycode, void *param)
{
	t_game		*game;
	t_sprites 	*sprites;
	t_player	*player;
	t_exit	*exit;

	game = (t_game *)param;
	sprites = &game->sprites;
	player = &game->player;
	exit = &game->exit;
	if (keycode == KEY_ESC)
		close_win(param);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player_up(game, player, &sprites->up);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player_right(game, player, &sprites->right);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player_down(game, player, &sprites->down);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player_left(game, player, &sprites->left);
	ft_printf("(btns = %d)  px = %d   py = %d  ex = %d  ey = %d\n", game->nbtns, player->x, player->y, exit->x, exit->y);
	return (0);
}

void ft_sleep(void)
{
	size_t	i;

	i = 0;
	while (i < 390000000)
		i++;	
}
