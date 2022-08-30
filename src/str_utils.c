/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:24:58 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/28 16:50:30 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i] && s2[i]) && s1[i] == s2[i]) && i + 1 < n)
		i++;
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!s)
		return (NULL);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	j = -1;
	i -= 1;
	while (s2[++j])
		s[++i] = s2[j];
	s[i + 1] = 0;
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (i == ft_strlen(s) && s[i] != c)
		return (0);
	return ((char *)(s + i));
}

void	put_moves(t_game *game, int moves)
{
	char	*num;
	char	*join;

	ft_printf("%d\n", game->nmoves);
	put_image(game, game->bsprites.mask.img, 2, 0);
	put_image(game, game->bsprites.mask.img, 3, 0);
	put_image(game, game->bsprites.mask.img, 4, 0);
	put_image(game, game->bsprites.mask.img, 5, 0);
	num = ft_itoa(moves);
	join = ft_strjoin("moves: ", num);
	mlx_string_put(game->mlx, game->win, 79, \
		-1, 0xffffff, join);
	free(num);
	free(join);
}
