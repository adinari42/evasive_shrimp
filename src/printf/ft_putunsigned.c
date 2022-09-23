/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:25:30 by adinari           #+#    #+#             */
/*   Updated: 2022/05/12 21:40:23 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nbr)
{
	int		conv_len;

	conv_len = 0;
	if (nbr < 10)
		conv_len += ft_putchar(nbr + 48);
	else
	{
		conv_len += ft_putunsigned(nbr / 10);
		conv_len += ft_putunsigned(nbr % 10);
	}
	return (conv_len);
}
