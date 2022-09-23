/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 05:37:51 by adinari           #+#    #+#             */
/*   Updated: 2022/05/31 20:05:37 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
*characters after 9(10 to 16) are converted into alphabet by adding 87 or 65 
depending on the case
*87 is a(97) - 10, conversion to lowercase.
*55 is A(65) - 10, conversion to uppercase
*/
int	ft_printhex(unsigned int ptr, char c)
{
	int	ptr_len;

	ptr_len = 0;
	if (ptr == 0)
	{
		ptr_len += ft_putchar('0');
		return (ptr_len);
	}	
	if (ptr >= 16)
	{
		ptr_len += ft_printhex(ptr / 16, c);
		ptr_len += ft_printhex(ptr % 16, c);
	}
	else
	{
		if (ptr <= 9)
			ptr_len += ft_putchar(ptr + '0');
		else
			if (c == 'x')
				ptr_len += ft_putchar(ptr + 87);
		else if (c == 'X')
			ptr_len += ft_putchar(ptr + 55);
	}
	return (ptr_len);
}
