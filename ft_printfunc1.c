/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfunc1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:45:33 by kmoutaou          #+#    #+#             */
/*   Updated: 2021/11/28 16:59:05 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char	c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		*len += 1;
		i++;
	}
	return ;
}

void	ft_putnbr(int n, int *len)
{
	char	nn;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
		*len += 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		*len += 1;
		ft_putnbr(n * -1, len);
	}
	else if (n >= 0 && n <= 9)
	{
		nn = n + '0';
		write(1, &nn, 1);
		*len += 1;
	}
	else
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
}

void	ft_putnbr_u(unsigned int n, int *len)
{
	char	nn;

	if (n <= 9)
	{
		nn = n + '0';
		write(1, &nn, 1);
		*len += 1;
	}
	else
	{
		ft_putnbr_u(n / 10, len);
		ft_putnbr_u(n % 10, len);
	}
}
