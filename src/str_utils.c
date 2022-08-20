/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:20:02 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/20 20:20:06 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

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

void	*ft_memset(void *b, int c, size_t len)
{
	while (len)
		((unsigned char *)b)[--len] = c;
	return (b);
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
