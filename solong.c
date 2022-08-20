/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:09:04 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/20 20:56:09 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int	ac,char	**av)
{
	void	*mlx;
	void	*win1;
	t_game	game;

	if (ac != 2)
		throwerror("You need to provide one map");
	ft_memset(&game, 0, sizeof(game));
	game.mapfile = av[1];
	setmap(&game);
	check_keys(&game);
	check_rectangular_walls(&game);

	mlx = mlx_init();
	win1 = mlx_new_window(mlx, game.mapwidth * 32, game.mapheight * 32, "win1");
	mlx_loop(mlx);

}