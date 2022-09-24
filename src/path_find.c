/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:18:13 by adinari           #+#    #+#             */
/*   Updated: 2022/09/24 22:39:16 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evasive_shrimp.h"

int	is_safe(int x, int y)
{
	printf("%c\n", g_data.map[x][y]);
	if (g_data.map[x][y] == '0' || g_data.map[x][y] == 'C'
		|| g_data.map[x][y] == 'P')
		return (1);
	return (0);
}

void	backtrack(int x, int y)
{
	if (g_data.map[x][y] == 'C')
		g_data.map[x][y] = 'C';
	else if (g_data.map[x][y] == 'W')
		g_data.map[x][y] = 'W';
	else
		g_data.map[x][y] = 'V';
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
		if (path_check_util(x + 1, y) == 1)
			return (1);
		if (path_check_util(x, y + 1) == 1)
			return (1);
		if (path_check_util(x - 1, y) == 1)
			return (1);
		if (path_check_util(x, y - 1) == 1)
			return (1);
		backtrack(x, y);
		return (0);
	}
	return (0);
}

int	path_check(void)
{
	if (!path_check_util(g_data.player_y / 32, g_data.player_x / 32))
		return (0);
	return (1);
}
