/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 05:47:12 by adinari           #+#    #+#             */
/*   Updated: 2022/09/22 22:21:32 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evasive_shrimp.h"

int	save_map(int dim[2], char *path)
{
	int		i;
	int		fd;
	char	*line;

	line = NULL;
	fd = open(path, O_RDONLY);
	i = 0;
	g_data.map = malloc(sizeof(char *) * (dim[1] + 1));
	if (!g_data.map)
		return (0);
	g_data.map[i] = NULL;
	i = 0;
	line = get_next_line(fd);
	while (i < dim[1])
	{
		g_data.map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (1);
}

void	render_floor(mlx_t *mlx, int x, int y)
{
	g_data.img2[0] = mlx_load_png("pngs/floor.png");
	g_data.c_img = mlx_texture_to_image(mlx, g_data.img2[0]);
	mlx_delete_texture(g_data.img2[0]);
	mlx_image_to_window(mlx, g_data.c_img, x, y);
}

/*renders floor texture first then the proper texture on top of it next*/
void	render_texture(mlx_t *mlx, char *path, int *x, int y)
{
	render_floor(mlx, *x, y);
	g_data.img2[1] = mlx_load_png(path);
	g_data.c_img = mlx_texture_to_image(mlx, g_data.img2[1]);
	mlx_delete_texture(g_data.img2[1]);
	mlx_image_to_window(mlx, g_data.c_img, *x, y);
	mlx_delete_image(mlx, g_data.img);
	*x += 32;
}

void	choose_texture(mlx_t *mlx, int map_parse, int *x, int y)
{
	if (map_parse == '1')
		render_texture(mlx, "pngs/wall.png", x, y);
	else if (map_parse == '0')
		render_texture(mlx, "pngs/floor.png", x, y);
	else if (map_parse == 'P')
	{
		g_data.player_x = *x;
		g_data.player_y = y;
		render_texture(mlx, "pngs/floor.png", x, y);
	}
	else if (map_parse == 'C' || map_parse == 'W')
		render_texture(mlx, "pngs/crypto.png", x, y);
	else if (map_parse == 'E')
		render_texture(mlx, "pngs/chest_closed.png", x, y);
}

void	render_map(mlx_t *mlx, char *path)
{
	int				fd;
	char			*map_parse;
	int				i;
	int				x;
	int				y;

	x = 0;
	y = 0;
	fd = open(path, O_RDONLY);
	map_parse = get_next_line(fd);
	i = 0;
	while (map_parse[i])
	{	
		if (map_parse[i] == '\n')
		{
			free(map_parse);
			map_parse = get_next_line(fd);
			i = 0;
			x = 0;
			y += 32;
		}
		else
			choose_texture(mlx, map_parse[i++], &x, y);
	}
	free(map_parse);
}
