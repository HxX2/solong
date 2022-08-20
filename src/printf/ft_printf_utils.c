/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:02:53 by zlafou            #+#    #+#             */
/*   Updated: 2022/04/16 20:00:54 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = -1;
	if (!str)
	{	
		ft_putstr("(null)", len);
		return ;
	}
	while (str[++i])
		*len += ft_putchar(str[i]);
}

void	ft_putnbr(long long n, int	*len)
{
	unsigned int	nb;

	if (n < 0)
	{
		*len += ft_putchar('-');
		n *= -1;
	}
	nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else
		*len += ft_putchar(nb + '0');
}

void	ft_puthexx(unsigned long long nb, char c, int *len)
{
	char	*base;

	if (c == 'p')
	{
		ft_putstr("0x", len);
		c = 'x';
	}
	base = "0123456789ABCDEF";
	if (c == 'x')
		base = "0123456789abcdef";
	if (nb > 15)
	{
		ft_puthexx(nb / 16, c, len);
		ft_puthexx(nb % 16, c, len);
	}
	else
		*len += ft_putchar(base[nb]);
}
