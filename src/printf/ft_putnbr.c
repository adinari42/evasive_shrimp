/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:48:35 by adinari           #+#    #+#             */
/*   Updated: 2022/05/12 21:39:34 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n > MAX || n < MIN)
		return (i);
	if (n == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		i += ft_putchar(n + 48);
		return (i);
	}
	else
		i += ft_putnbr(n / 10);
	i += ft_putnbr(n % 10);
	return (i);
}
