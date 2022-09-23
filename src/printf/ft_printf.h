/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:47:58 by adinari           #+#    #+#             */
/*   Updated: 2022/09/22 23:29:56 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define MAX 2147483647
# define MIN -2147483648

int	ft_printf(const char *argc, ...);
int	ft_printptr(unsigned long ptr);
int	ft_printhex(unsigned int ptr, char c);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int nbr);
int	ft_printhex(unsigned int ptr, char c);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	print_format(va_list next_arg, int arg_flag);
int	ft_strlen(const char *s);

#endif
