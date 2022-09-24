/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:31:25 by adinari           #+#    #+#             */
/*   Updated: 2022/09/24 15:53:05 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evasive_shrimp.h"

//handles exit message for get_dimensions>>parse_line
void	perror_exit(int error)
{
	if (error == 1)
	{
		perror("Error : Multiple exits\n");
		exit(1);
	}
	else if (error == 2)
	{
		perror("Error : Multiple starts\n");
		exit(1);
	}
	else if (error == 3)
	{
		perror("Error : invalid character\n");
		exit(1);
	}
}

//initializes first line for get_dimensions
char	*init_line(int fd)
{
	char	*line;

	if (fd == -1)
	{
		perror("Error\ncannot open file\n");
		exit(1);
	}
	line = get_next_line(fd);
	return (line);
}

void	update_chest(void *param)
{
	int	i;
	int	j;

	i = 0;
	while (g_data.map[i])
	{
		j = 0;
		while (g_data.map[i][j])
		{
			if (g_data.map[i][j] == 'E')
			{
				open_chest(param, &j, i);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if ((n > 2147483647 || n < -2147483648) && fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	else
		ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}
