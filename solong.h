/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:11:11 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/20 20:45:05 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "src/printf/ft_printf.h"
// # include "src/gnl/get_next_line.h"

# define BUFFER_SIZE 1024

typedef struct s_alloc
{
	char	**map;
	char	*smap;
}		t_alloc;

typedef struct s_game
{
	char	*mapfile;
	int		mapwidth;
	int		mapheight;
	t_alloc	alloc;
}		t_game;

void	check_rectangular_walls(t_game	*game);
void	setmap(t_game	*game);
void	check_keys(t_game	*game);

char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	throwerror(char *msg);
void	*ft_calloc(size_t n);

#endif