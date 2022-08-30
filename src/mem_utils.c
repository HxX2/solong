/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:20:02 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/29 22:35:37 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_rwipe(void *ptr, int plvl)
{
	size_t	i;
	int		b;
	void	**p;

	p = (void **)ptr;
	b = 1;
	if (plvl < 0)
	{
		plvl *= -1;
		b = 0;
	}
	if (plvl > 1)
	{
		i = -1;
		while (p && p[++i])
		{
			if (plvl > 2)
				ft_rwipe((void **)p[i], -1 * (plvl - 1));
			free(p[i]);
		}
	}
	if (b)
		free(p);
}

void	*ft_calloc(size_t n)
{
	void		*ptr;

	ptr = malloc(n);
	if (!ptr)
		return (0);
	while (n)
		((unsigned char *)ptr)[--n] = 0;
	return (ptr);
}

void	destroy_sprites(t_game *game)
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
}
