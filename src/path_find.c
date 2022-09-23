/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:18:13 by adinari           #+#    #+#             */
/*   Updated: 2022/09/22 22:28:18 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evasive_shrimp.h"

/*void printmaze()
{
	int	i;

	i = 0;
	while (g_data.map[i])
	{
		printf("%s\n", g_data.map[i]);
		i++;
	}
}*/

int	is_safe(int x, int y)
{
	if (g_data.map[x][y] == '0' || g_data.map[x][y] == 'C'
		|| g_data.map[x][y] == 'P')
		return (1);
	return (0);
}

int	path_check_util(int x, int y)
{
	if (g_data.map[x][y] == 'E')
	{
		g_data.map[g_data.player_y / 32][g_data.player_x / 32] = 'P';
		return (1);
	}
	if (is_safe(x, y))
	{
		if (g_data.map[x][y] == 'V' || g_data.map[x][y] == 'W')
			return (0);
		if (g_data.map[x][y] == 'C')
			g_data.map[x][y] = 'W';
		else
			g_data.map[x][y] = 'V';
		if (path_check_util(x + 1, y) == true)
			return (true);
		if (path_check_util(x, y + 1) == true)
			return (true);
		if (path_check_util(x - 1, y) == true)
			return (true);
		if (path_check_util(x, y - 1) == true)
			return (true);
		g_data.map[x][y] = '1';
		return (0);
	}
	return (0);
}

int	path_check(void)
{
	if (!path_check_util(g_data.player_y / 32, g_data.player_x / 32))
	{
		return (0);
	}
	return (1);
}
