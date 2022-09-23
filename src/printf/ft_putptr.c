/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:46:15 by adinari           #+#    #+#             */
/*   Updated: 2022/05/31 20:03:41 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** + '0'(48) converts int to char.
** - 10 + 'a'(87) is conversion of this int value to lowercase char.
*/
int	ft_printptr(unsigned long ptr)
{
	int	ptr_len;

	ptr_len = 0;
	if (ptr <= 9)
			ptr_len += ft_putchar(ptr + 48);
	else if (ptr > 9 && ptr < 16)
		ptr_len += ft_putchar(ptr + 87);
	else
	{
		ptr_len += ft_printptr(ptr / 16);
		ptr_len += ft_printptr(ptr % 16);
	}
	return (ptr_len);
}
