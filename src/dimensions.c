/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 04:21:52 by adinari           #+#    #+#             */
/*   Updated: 2022/09/24 15:50:02 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evasive_shrimp.h"

void	check_lastline(char	*last_line, int last_width)
{
	int	i;

	i = 0;
	while (last_line[i] && i < last_width)
	{
		if (last_line[i] != '1')
		{
			perror("Error 1\nmap not closed with walls\n");
			exit(1);
		}
		i++;
	}
	if (g_data.e_count != 1 || g_data.c_count < 1 || g_data.p_count != 1)
	{
		perror("Error 2\n missing element\n");
		exit(1);
	}
}

void	check_firstline(char	*first_line)
{
	int	i;

	i = 0;
	while (first_line[i] && first_line[i] != '\n')
	{
		if (first_line[i] != '1' )
		{
			perror("Error 2\nmap not closed with walls\n");
			free(first_line);
			exit(1);
		}
		i++;
	}
}

void	check_line(char	*line, int last_width)
{
	int		i;
	char	*tmp;

	tmp = line;
	i = 0;
	if (tmp[i] != '1')
	{
		perror("Error\nmap not closed with walls\n");
		free(line);
		exit(1);
	}
	while (tmp[i] && i < last_width - 1)
		i++;
	if (tmp[i] != '1' && i != last_width)
	{
		perror("Error\nmap not closed with walls\n");
		free(line);
		exit(1);
	}
	return ;
}

int	parse_line(char	*line, int dim[2])
{
	dim[0] = 0;
	dim[1]++;
	while (line[dim[0]] && line[dim[0]] != '\n')
	{
		if (line[dim[0]] == 'C')
			g_data.c_count++;
		else if (line[dim[0]] == 'E' && g_data.e_count == 0)
			g_data.e_count = 1;
		else if (line[dim[0]] == 'E' && g_data.e_count == 1)
			perror_exit(1);
		else if (line[dim[0]] == 'P' && g_data.p_count == 0)
			g_data.p_count = 1;
		else if (line[dim[0]] == 'P' && g_data.p_count == 1)
			perror_exit(2);
		else if (line[dim[0]] != '1' && line[dim[0]] != '0')
			perror_exit(3);
		dim[0]++;
	}
	return (dim[0]);
}

void	get_dimensions(int dim[2], char *path)
{
	t_line	line;
	int		fd;

	fd = open(path, O_RDONLY);
	line.line = init_line(fd);
	line.last_line = line.line;
	check_firstline(line.last_line);
	while (line.line != NULL)
	{
		line.last_width = dim[0];
		dim[0] = 0;
		dim[1]++;
		dim[0] = parse_line(line.line, &dim[2]);
		if (line.last_width != 0 && dim[0] != line.last_width)
		{
			perror("Error :\nMap not rectangular");
			exit(1);
		}
		if (line.line != NULL)
			check_line(line.line, line.last_width);
		free(line.line);
		line.last_line = line.line;
		line.line = get_next_line(fd);
	}
	check_lastline(line.last_line, line.last_width);
}
