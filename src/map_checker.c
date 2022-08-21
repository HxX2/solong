/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:36:14 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/21 14:28:13 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	throwerror(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(1);
}

void	check_keys(t_game	*game)
{
	int		i;
	char	*s;
	char	*keys;

	s = game->alloc.smap;
	keys = "P01CE\n";
	i = 0;
	while (s[i])
	{
		if (s[0] == '\n' || (s[i] == '\n' && (s[i + 1] == '\n' || !s[i + 1])))
			throwerror("Map is not rectangular");
		if (!ft_strchr(keys, s[i]))
			throwerror("Unkown key in the map");
		if (s[i] == 'C')
			game->nbtns += 1;
		i++;
	}
	if (!ft_strchr(s, 'P'))
		throwerror("There is no player");
	if (ft_strchr((ft_strchr(s, 'P') + 1), 'P'))
		throwerror("Too many players");
	if (!ft_strchr(s, 'C'))
		throwerror("There is no collectible");
	if (!ft_strchr(s, 'E'))
		throwerror("There is no exit");
}

void	setmap(t_game	*game)
{
	int		mapfd;
	char	*buff;
	char	*tmp;
	ssize_t	eof;

	buff = malloc(sizeof(char) * 1025);
	mapfd = open(game->mapfile, O_RDONLY);
	eof = 1;
	game->alloc.smap = ft_strjoin("", "");
	while (eof)
	{
		eof = read(mapfd, buff, 1024);
		buff[eof] = 0;
		tmp = game->alloc.smap;
		game->alloc.smap = ft_strjoin(tmp, buff);
		free(tmp);
	}
	game->alloc.map = ft_split(game->alloc.smap, '\n');
}

void	check_rectangular_walls(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = game->alloc.map;
	i = 0;
	while (map[i])
	{
		if (map[i + 1] && ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			throwerror("map is not rectangular");
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			throwerror("map is not surrounded by walls");
		i++;
	}
	game->mapheight = i;
	game->mapwidth = ft_strlen(map[0]);
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			throwerror("map is not surrounded by walls");
		if (map[i - 1][j] != '1')
			throwerror("map is not surrounded by walls");
		j++;
	}
}