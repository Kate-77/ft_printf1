/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:33:23 by kmoutaou          #+#    #+#             */
/*   Updated: 2022/10/10 14:12:23 by kmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char c)
{
	char	*str;

	str = "csdipuxX%";
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	ft_check(const char *format, int i, int *len, va_list args)
{
	if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (format[i] == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (format[i] == 'p')
	{
		ft_putstr("0x", len);
		ft_putpointer(va_arg(args, unsigned long), "0123456789abcdef", len);
	}
	else if (format[i] == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format[i] == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10, len);
	else if (format[i] == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef", 16, len);
	else if (format[i] == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 16, len);
	else if (format[i] == '%')
		ft_putchar('%', len);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, format);	
	while (format[i])
	{
		if (format[i] == '%' && format[i+1] && ft_check_format(format[i+1]))
		{
			ft_check(format, i+1, &len, args);
			i++;
		}
		else
			ft_putchar(format[i] , &len);
		i++;
	}
	va_end(args);
	return (len);
}

int	main()
{
	ft_printf("ho %d\n", ft_printf("%x\n", -2147483648));
}
