/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bevent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:19:53 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/29 20:19:11 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	put_enemy(t_game *game, t_sprites *sprites, int x, int y)
{
	put_image(game, sprites->ground.img, x, y);
	put_image(game, game->bsprites.enemy.img, x, y);
}

void	destroy_sprites(t_game	*game)
{
	mlx_destroy_image(game->mlx, game->sprites.ground.img);
	mlx_destroy_image(game->mlx, game->sprites.exitclose.img);
	mlx_destroy_image(game->mlx, game->sprites.exitopen.img);
	mlx_destroy_image(game->mlx, game->sprites.btnup.img);
	mlx_destroy_image(game->mlx, game->sprites.btndown.img);
	mlx_destroy_image(game->mlx, game->sprites.cornerdownleft.img);
	mlx_destroy_image(game->mlx, game->sprites.cornerdownright.img);
	mlx_destroy_image(game->mlx, game->sprites.cornerupleft.img);
	mlx_destroy_image(game->mlx, game->sprites.cornerupright.img);
	mlx_destroy_image(game->mlx, game->sprites.player.img);
	mlx_destroy_image(game->mlx, game->sprites.playerdone.img);
	mlx_destroy_image(game->mlx, game->sprites.down.img);
	mlx_destroy_image(game->mlx, game->sprites.left.img);
	mlx_destroy_image(game->mlx, game->sprites.right.img);
	mlx_destroy_image(game->mlx, game->sprites.up.img);
	mlx_destroy_image(game->mlx, game->sprites.wall.img);
	mlx_destroy_image(game->mlx, game->sprites.walldown.img);
	mlx_destroy_image(game->mlx, game->sprites.wallleft.img);
	mlx_destroy_image(game->mlx, game->sprites.wallright.img);
	mlx_destroy_image(game->mlx, game->sprites.wallup.img);
	destroy_bsprites(game);
}

void	destroy_bsprites(t_game	*game)
{
	mlx_destroy_image(game->mlx, game->bsprites.edown.img);
	mlx_destroy_image(game->mlx, game->bsprites.eup.img);
	mlx_destroy_image(game->mlx, game->bsprites.eleft.img);
	mlx_destroy_image(game->mlx, game->bsprites.eright.img);
	mlx_destroy_image(game->mlx, game->bsprites.exitlight.img);
	mlx_destroy_image(game->mlx, game->bsprites.mask.img);
	mlx_destroy_image(game->mlx, game->bsprites.pdead.img);
}

int	move_enemies(t_game *game)
{
	static int	count = 0;
	int			i;

	i = -1;
	while (++i < game->nenemies || !game->nenemies)
	{
		game->isdead = (game->nenemies
				&& ((is_on_player(game, game->enemies[i].x, game->enemies[i].y)
						|| is_on_enemy(game, game->player.x, game->player.y))));
		if (game->isdead || (game->player.y == game->exit.y
				&& game->player.x == game->exit.x))
			return (mlx_print(game));
		if (count < 1500)
			return (0 * ++count);
		if (!game->nenemies)
			break ;
		else
			game->f[rand() % 4](game, &game->enemies[i]);
	}
	if (game->nbtns == 0)
		put_image(game, game->sprites.exitopen.img, game->exit.x, game->exit.y);
	animation(game);
	count = 0;
	return (0);
}

void	animation(t_game *game)
{
	t_sprite	*sprites;
	static int	i = 0;

	sprites = game->alloc.animation;
	sprites[0] = game->sprites.exitclose;
	sprites[1] = game->bsprites.exitlight;
	if (game->nbtns != 0)
		put_image(game, sprites[i].img, game->exit.x, game->exit.y);
	i++;
	i %= 2;
}
