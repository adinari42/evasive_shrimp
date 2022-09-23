/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:06:51 by adinari           #+#    #+#             */
/*   Updated: 2022/05/31 19:53:30 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	print_format(va_list next_arg, int arg_flag)
{
	int	output_len;

	output_len = 0;
	if (arg_flag == 'c')
		output_len += ft_putchar(va_arg(next_arg, int));
	else if (arg_flag == 's')
		output_len += ft_putstr(va_arg(next_arg, char *));
	else if (arg_flag == 'p')
	{
		output_len += ft_putstr("0x");
		output_len += ft_printptr(va_arg(next_arg, unsigned long));
	}
	else if (arg_flag == 'd' || arg_flag == 'i')
		output_len += ft_putnbr(va_arg(next_arg, int));
	else if (arg_flag == 'u')
		output_len += ft_putunsigned(va_arg(next_arg, unsigned int));
	else if (arg_flag == 'x' || arg_flag == 'X')
		output_len += ft_printhex(va_arg(next_arg, int), arg_flag);
	else if (arg_flag == '%')
		output_len += ft_putchar('%');
	return (output_len);
}

int	ft_printf(const char *argc, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, argc);
	while (argc[i])
	{
		if (argc[i] != '%')
		{
			j += ft_putchar(argc[i]);
		}
		else
		{
			i++;
			j += print_format(args, argc[i]);
		}
		i++;
	}
	va_end(args);
	return (j);
}
