/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:20:02 by zlafou            #+#    #+#             */
/*   Updated: 2022/08/22 22:25:47 by zlafou           ###   ########.fr       */
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

