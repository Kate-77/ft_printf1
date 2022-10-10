/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfunc0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:45:21 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/10/10 14:14:32 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char *base, unsigned int b_ln, int *len)
{
	if (nbr / b_ln)
	{
		ft_putnbr_base(nbr / b_ln, base, b_ln, len);
	}
	ft_putchar(base[nbr % b_ln], len);
}

void	ft_putpointer(unsigned long nbr, char *base, int *len)
{
	if (nbr / 16)
	{
		ft_putpointer(nbr / 16, base, len);
	}
	ft_putchar(base[nbr % 16], len);
}
