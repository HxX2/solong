/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:02:07 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/22 18:37:38 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	put_walls(t_game *game, t_sprites *sprites, int x, int y)
{
	if (x == 0 && y == 0)
		put_image(game, sprites->cornerupleft.img, x, y);
	else if (x == game->mapw - 1 && y == 0)
		put_image(game, sprites->cornerupright.img, x, y);
	else if (x == 0 && y == game->maph - 1)
		put_image(game, sprites->cornerdownleft.img, x, y);
	else if (x == game->mapw - 1 && y == game->maph - 1)
		put_image(game, sprites->cornerdownright.img, x, y);
	else if (x == 0)
		put_image(game, sprites->wallleft.img, x, y);
	else if (x == game->mapw - 1)
		put_image(game, sprites->wallright.img, x, y);
	else if (y == 0)
		put_image(game, sprites->wallup.img, x, y);
	else if (y == game->maph - 1)
		put_image(game, sprites->walldown.img, x, y);
	else
		put_image(game, sprites->wall.img, x, y);
}

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		img, x * 32, y * 32);
}

void	put_player(t_game *game, t_sprites *sprites, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	put_image(game, sprites->ground.img, x, y);
	put_image(game, sprites->player.img, x, y);
}

void	put_map(t_game *game, t_sprites *sprites)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->maph)
	{
		x = -1;
		while (++x < game->mapw)
		{
			if (game->alloc.map[y][x] == '0')
				put_image(game, sprites->ground.img, x, y);
			else if (game->alloc.map[y][x] == 'E')
			{
				game->exit.x = x;
				game->exit.y = y;
				put_image(game, sprites->exitclose.img, x, y);
			}
			else if (game->alloc.map[y][x] == 'C')
				put_image(game, sprites->btnup.img, x, y);
			else if (game->alloc.map[y][x] == 'P')
				put_player(game, sprites, x, y);
			else
				put_walls(game, sprites, x, y);
		}
	}
}
