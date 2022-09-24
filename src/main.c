/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:37:34 by adinari           #+#    #+#             */
/*   Updated: 2022/09/24 21:56:23 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evasive_shrimp.h"

void	free_and_exit(mlx_t *mlx)
{
	g_data.end = 0;
	mlx_delete_image(mlx, g_data.img);
	mlx_close_window(mlx);
}

void	init_player(mlx_t *mlx, int x, int y)
{
	g_data.img2[2] = mlx_load_png("pngs/shrimp.png");
	g_data.p_img = mlx_texture_to_image(mlx, g_data.img2[2]);
	mlx_image_to_window(mlx, g_data.p_img, x, y);
	mlx_delete_texture(g_data.img2[2]);
}

void	open_chest(mlx_t *mlx, int *x, int y)
{	
	render_floor(mlx, *x * 32, y * 32);
	g_data.img2[1] = mlx_load_png("pngs/chest_open.png");
	g_data.c_img = mlx_texture_to_image(mlx, g_data.img2[1]);
	mlx_image_to_window(mlx, g_data.c_img, *x * 32, y * 32);
	mlx_delete_texture(g_data.img2[1]);
}

void	init_variables(void)
{
	g_data.dim[0] = 0;
	g_data.dim[1] = 0;
	g_data.c_count = 0;
	g_data.e_count = 0;
	g_data.p_count = 0;
	g_data.n_moves = 0;
	g_data.end = 1;
}

int32_t	main(int argc, char **argv)
{
	mlx_t	*mlx;

	init_variables();
	get_dimensions(g_data.dim, argv[1]);
	if (!save_map(g_data.dim, argv[1]))
		exit(EXIT_FAILURE);
	mlx = mlx_init(g_data.dim[0] * TXT_WIDTH,
			g_data.dim[1] * TXT_HEIGHT, "MLX42", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	render_map(mlx, argv[1]);
	if (!path_check())
	{	
		perror("Error\nno valid path to reach exit\n");
		exit(1);
	}
	init_player(mlx, g_data.player_x, g_data.player_y);
	mlx_key_hook(mlx, &key_hook, mlx);
	if (g_data.end == 1)
		mlx_loop(mlx);
	mlx_terminate(mlx);
	free(g_data.map[1]);
	return (argc);
}
