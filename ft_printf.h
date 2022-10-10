/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:41:09 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/10/10 14:08:06 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr_base(unsigned int nbr, char *base, unsigned int b_ln, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_u(unsigned int n, int *len);
void	ft_putpointer(unsigned long nbr, char *base,  int *len);

#endif
