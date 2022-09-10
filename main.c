/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:37:34 by adinari           #+#    #+#             */
/*   Updated: 2022/09/10 05:35:51 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evasive_shrimp.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>
#define WIDTH 1000
#define HEIGHT 1000

mlx_image_t *player_img;
mlx_image_t *component_img;

void	render_floor(mlx_t *mlx, int x, int y)
{
	mlx_texture_t	*component_texture;

	component_texture = mlx_load_png("pngs/floor.png");
	component_img = mlx_texture_to_image(mlx, component_texture);
	mlx_image_to_window(mlx, component_img, x, y);
}

/*renders floor texture first then the proper texture on top of it next*/
void	render_texture(mlx_t *mlx,char *path, int *x, int y)
{
	mlx_texture_t	*component_texture;

	render_floor(mlx, *x, y);

	component_texture = mlx_load_png(path);
	component_img = mlx_texture_to_image(mlx, component_texture);
	mlx_image_to_window(mlx, component_img, *x, y);
	*x += 32;
}

void	player_move_up(mlx_t *mlx)
{
	int next_pos_x;
	int next_pos_y;
	int	f_x;
	int	f_y;

	next_pos_y = (player_img->instances[0].y - 5 )/ TXT_HEIGHT;
	next_pos_x = player_img->instances[0].x / TXT_WIDTH;
	f_x = player_img->instances[0].x;
	f_y = player_img->instances[0].y - 32;
	printf("next pos x %d y %d\n", next_pos_x, next_pos_y);
	if (g_data.map[next_pos_y][next_pos_x] == '1')
	{
		// printf("Wall... wall... wall.. \n");
		return;
	}
	if (g_data.map[next_pos_y][next_pos_x] == 'C')
	{
		g_data.C_count--;
		printf("%d collectibles left \n", g_data.C_count);
		g_data.map[next_pos_y][next_pos_x] = '0';
		render_floor(mlx, f_x, f_y);
		mlx_delete_image(mlx, player_img);
		mlx_texture_t *player_texture = mlx_load_png("pngs/shrimp.png");
		player_img = mlx_texture_to_image(mlx, player_texture);
		mlx_image_to_window(mlx, player_img, f_x, f_y + 32);
	}
	g_data.n_moves++;
	printf("number of moves = %d\n", g_data.n_moves);
	if (g_data.map[next_pos_y][next_pos_x] == 'E' && g_data.C_count == 0)
	{
		g_data.end = 0;
		free(g_data.map);
		int i = 0;
		while (i < g_data.img_height)
		{
			free(g_data.map[i]);
			i++;
		}
		mlx_delete_image(mlx, g_data.img);
		mlx_close_window(mlx);
		mlx_terminate(mlx);
		system("leaks so_long");
		exit(1);
	}
	 player_img->instances[0].y -= 32;
}

void	player_move_down(mlx_t *mlx)
{
	int next_pos_x;
	int next_pos_y;
	int	f_x;
	int	f_y;

	next_pos_y = (player_img->instances[0].y + 32)/ TXT_HEIGHT;
	next_pos_x = player_img->instances[0].x / TXT_WIDTH;
	f_x = player_img->instances[0].x;
	f_y = player_img->instances[0].y + 32;
	printf("next pos x %d y %d\n", next_pos_x, next_pos_y);
	if (g_data.map[next_pos_y][next_pos_x] == '1')
	{
		// printf("Wall... wall... wall.. \n");
		return;
	}
	if (g_data.map[next_pos_y][next_pos_x] == 'C')
	{
		g_data.C_count--;
		printf("%d collectibles left \n", g_data.C_count);
		g_data.map[next_pos_y][next_pos_x] = '0';
		render_floor(mlx, f_x, f_y);
		mlx_delete_image(mlx, player_img);
		mlx_texture_t *player_texture = mlx_load_png("pngs/shrimp.png");
		player_img = mlx_texture_to_image(mlx, player_texture);
		mlx_image_to_window(mlx, player_img, f_x, f_y - 32);
	}
	g_data.n_moves++;
	printf("number of moves = %d\n", g_data.n_moves);
	if (g_data.map[next_pos_y][next_pos_x] == 'E' && g_data.C_count == 0)
	{
		g_data.end = 0;
		free(g_data.map);
		int i = 0;
		while (i < g_data.img_height)
		{
			free(g_data.map[i]);
			i++;
		}
		mlx_delete_image(mlx, g_data.img);
		mlx_close_window(mlx);
		mlx_terminate(mlx);
		system("leaks so_long");
		exit(1);
	}
	 player_img->instances[0].y += 32;
}

void	player_move_right(mlx_t *mlx)
{
	int next_pos_x;
	int next_pos_y;
	int	f_x;
	int	f_y;

	next_pos_y = (player_img->instances[0].y)/ TXT_HEIGHT;
	next_pos_x = (player_img->instances[0].x  + 32) / TXT_WIDTH;
	f_x = player_img->instances[0].x + 32;
	f_y = player_img->instances[0].y;
	printf("next pos x %d y %d\n", next_pos_x, next_pos_y);
	if (g_data.map[next_pos_y][next_pos_x] == '1')
	{
		// printf("Wall... wall... wall.. \n");
		return;
	}
	if (g_data.map[next_pos_y][next_pos_x] == 'C')
	{
		g_data.C_count--;
		printf("%d collectibles left \n", g_data.C_count);
		g_data.map[next_pos_y][next_pos_x] = '0';
		render_floor(mlx, f_x, f_y);
		mlx_delete_image(mlx, player_img);
		mlx_texture_t *player_texture = mlx_load_png("pngs/shrimp.png");
		player_img = mlx_texture_to_image(mlx, player_texture);
		mlx_image_to_window(mlx, player_img, f_x - 32, f_y);
	}
	g_data.n_moves++;
	printf("number of moves = %d\n", g_data.n_moves);
	if (g_data.map[next_pos_y][next_pos_x] == 'E' && g_data.C_count == 0)
	{
		g_data.end = 0;
		free(g_data.map);
		int i = 0;
		while (i < g_data.img_height)
		{
			free(g_data.map[i]);
			i++;
		}
		mlx_delete_image(mlx, g_data.img);
		mlx_close_window(mlx);
		mlx_terminate(mlx);
		system("leaks so_long");
		exit(1);
	}
	 player_img->instances[0].x += 32;
}

void	player_move_left(mlx_t *mlx)
{
	int next_pos_x;
	int next_pos_y;
	int	f_x;
	int	f_y;

	next_pos_y = (player_img->instances[0].y)/ TXT_HEIGHT;
	next_pos_x = (player_img->instances[0].x  - 5) / TXT_WIDTH;
	f_x = player_img->instances[0].x - 32;
	f_y = player_img->instances[0].y;
	if (g_data.map[next_pos_y][next_pos_x] == '1')
	{
		return;
	}
	if (g_data.map[next_pos_y][next_pos_x] == 'C')
	{
		g_data.C_count--;
		printf("%d collectibles left \n", g_data.C_count);
		g_data.map[next_pos_y][next_pos_x] = '0';
		render_floor(mlx, f_x, f_y);
		mlx_delete_image(mlx, player_img);
		mlx_texture_t *player_texture = mlx_load_png("pngs/shrimp.png");
		player_img = mlx_texture_to_image(mlx, player_texture);
		mlx_image_to_window(mlx, player_img, f_x + 32, f_y);
	}
	g_data.n_moves++;
	printf("number of moves = %d\n", g_data.n_moves);
	if (g_data.map[next_pos_y][next_pos_x] == 'E' && g_data.C_count == 0)
	{
		g_data.end = 0;
		free(g_data.map);
		int i = 0;
		while (i < g_data.img_height)
		{
			free(g_data.map[i]);
			i++;
		}
		mlx_delete_image(mlx, g_data.img);
		mlx_close_window(mlx);
		mlx_terminate(mlx);
		system("leaks so_long");
		exit(1);
	}
	player_img->instances[0].x -= 32;
}
void	free_assets(mlx_t *mlx, mlx_texture_t *player_texture)
{
	mlx_delete_image(mlx, component_img);
	mlx_delete_image(mlx, player_img);
	mlx_delete_texture(player_texture);

}
void	open_chest(mlx_t *mlx, int *x, int y)
{
	mlx_texture_t	*component_texture;

	render_floor(mlx, *x * 32, y * 32);
	component_texture = mlx_load_png("pngs/chest_open.png");
	component_img = mlx_texture_to_image(mlx, component_texture);
	mlx_image_to_window(mlx, component_img, *x * 32, y * 32);
	free(component_texture);
}

void	key_hook(mlx_key_data_t keydata, void* param)
{
	if(keydata.action == 1)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(param);
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			player_move_up(param);	
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			player_move_down(param);
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			player_move_left(param);
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			player_move_right(param);
	}
	if (g_data.C_count == 0)
	{
		int i = 0;
		while (g_data.map[i] )
		{
			int j = 0;
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
}

/*void	hook(void *param)
{

	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		player_move_up();	
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		player_move_down();
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		player_move_left();
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		player_move_right();
}*/
// wall : 32x32






void	render_map(mlx_t *mlx)
{
	int 			fd;
	char 			*map_parse;
	int				i;
	int				x;
	int				y;

	x = 0;
	y = 0;
	fd = open("map1.ber", O_RDONLY);
	map_parse = get_next_line(fd);
	i = 0;
	while (map_parse[i])
	{
		printf(" %c ", map_parse[i]);
		if (map_parse[i] == '\n')
		{
			free(map_parse);
			map_parse = get_next_line(fd);
			i = 0;
			x = 0;
			y += 32;
		}
		else if (map_parse[i] == '1')
		{
			render_texture(mlx, "pngs/wall.png", &x, y);
			i++;
		}
		else if (map_parse[i] == '0')
		{
			render_texture(mlx, "pngs/floor.png", &x, y);
			i++;
		}
		else if (map_parse[i] == 'P')
		{
			g_data.player_x = x;
			g_data.player_y = y;
			render_texture(mlx, "pngs/floor.png", &x, y);
			i++;
		}
		else if (map_parse[i] == 'C')
		{
			render_texture(mlx, "pngs/crypto.png", &x, y);
			i++;
		}
		else if (map_parse[i] == 'E')
		{
			render_texture(mlx, "pngs/chest_closed.png", &x, y);
			i++;
		}
		else
			i++;
	}
	free(map_parse);
}

void	save_map(int dim[2])
{
	g_data.map = malloc(sizeof(char *) * (dim[1] + 1));
	//protect malloc
	int i = 0;
	while (i < dim[1])
	{
		g_data.map[i] = malloc(sizeof(char) * (dim[0] + 1));
		i++;
	}
	g_data.map[i] = NULL;
	int fd = open("map1.ber", O_RDONLY);
	char *line = NULL;
	i = 0;
	line = get_next_line(fd);
	while (i < dim[1])
	{
		g_data.map[i] = line;
		// free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

void  get_dimensions(int dim[2])
{
	int 			fd;
	char			*line;
	int				last_width;

	dim[0] = 0;
	dim[1] = 0;
	g_data.C_count = 0;
	g_data.n_moves = 0;
	fd = open("map1.ber", O_RDONLY);
	if (fd == -1)
	{
		//error
	}
	line = get_next_line(fd);
	while(line)
	{
		last_width = dim[0];
		dim[0] = 0;
		dim[1]++;
		while (line[dim[0]])
		{
			if (line[dim[0]] == 'C')//
				g_data.C_count++;//
			dim[0]++;
		}
		free(line);
		if (dim[0] != last_width)
		{
			// exit(1);
		}
		line = get_next_line(fd);
	}
	free(line);
	printf("%d\n", g_data.C_count);
}

void	init_player(mlx_t *mlx)
{
	mlx_texture_t 	*player_texture = mlx_load_png("pngs/shrimp.png");
	player_img = mlx_texture_to_image(mlx, player_texture);
	mlx_image_to_window(mlx, player_img, g_data.player_x, g_data.player_y);
}
int32_t	main(void)
{
	mlx_t	*mlx;
	int		dim[2];

	g_data.end = 1;
	get_dimensions(dim);
	save_map(dim);
	printf("dimensions %d %d\n", dim[0], dim[1]);
	mlx = mlx_init(dim[0] * TXT_WIDTH, dim[1] * TXT_HEIGHT, "MLX42", false);
	if (!mlx)
		exit(EXIT_FAILURE);

	render_map(mlx);

	init_player(mlx);
	
	mlx_key_hook(mlx, &key_hook, mlx);	//mlx_loop_hook(mlx, &hook, mlx)
	if (g_data.end == 1)
		mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
//create map
//parse it using getnextline and print tiles