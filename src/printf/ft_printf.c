/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:51:32 by zlafou            #+#    #+#             */
/*   Updated: 2022/04/16 20:00:22 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void	ft_fselector(va_list ap, const char *str, int *len)
{
	if (str[0] == 'c')
		*len += ft_putchar(va_arg(ap, int));
	else if (str[0] == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (str[0] == 'd')
		ft_putnbr(va_arg(ap, int), len);
	else if (str[0] == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (str[0] == 'u')
		ft_putnbr(va_arg(ap, unsigned int), len);
	else if (str[0] == 'x')
		ft_puthexx(va_arg(ap, unsigned int), str[0], len);
	else if (str[0] == 'X')
		ft_puthexx(va_arg(ap, unsigned int), str[0], len);
	else if (str[0] == 'p')
		ft_puthexx(va_arg(ap, unsigned long long), str[0], len);
	else if (str[0] == '%')
		*len += ft_putchar(str[0]);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start (ap, str);
	while (*str)
	{
		if (*str == '%')
		{	
			str++;
			ft_fselector(ap, str, &len);
			++str;
		}
		else
			len += ft_putchar(*(str++));
	}
	va_end(ap);
	return (len);
}
