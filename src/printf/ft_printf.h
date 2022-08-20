/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:09:30 by zlafou            #+#    #+#             */
/*   Updated: 2022/04/16 20:00:47 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

void	ft_puthexx(unsigned long long nb, char c, int *len);
void	ft_putnbr(long long nb, int *len);
int		ft_printf(const char *str, ...);
void	ft_putstr(char *str, int *len);
int		ft_putchar(int c);
#endif