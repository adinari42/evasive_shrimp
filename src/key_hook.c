/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:11:43 by adinari           #+#    #+#             */
/*   Updated: 2022/09/24 15:54:00 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evasive_shrimp.h"

void	player_move_up(mlx_t *mlx)
{
	int	next_pos_x;
	int	next_pos_y;
	int	f_x;
	int	f_y;

	next_pos_y = (g_data.p_img->instances[0].y - 32) / TXT_HEIGHT;
	next_pos_x = g_data.p_img->instances[0].x / TXT_WIDTH;
	f_x = g_data.p_img->instances[0].x;
	f_y = g_data.p_img->instances[0].y - 32;
	if (g_data.map[next_pos_y][next_pos_x] == '1')
		return ;
	if (g_data.map[next_pos_y][next_pos_x] == 'C'
		|| g_data.map[next_pos_y][next_pos_x] == 'W')
	{
		g_data.c_count--;
		g_data.map[next_pos_y][next_pos_x] = '0';
		render_floor(mlx, f_x, f_y);
		mlx_delete_image(mlx, g_data.p_img);
		init_player(mlx, f_x, f_y + 32);
	}
	g_data.n_moves++;
	ft_printf("number of moves = %d\n", g_data.n_moves);
	if (g_data.map[next_pos_y][next_pos_x] == 'E' && g_data.c_count == 0)
		free_and_exit(mlx);
	g_data.p_img->instances[0].y -= 32;
}

void	player_move_down(mlx_t *mlx)
{
	int	next_pos_x;
	int	next_pos_y;
	int	f_x;
	int	f_y;

	next_pos_y = (g_data.p_img->instances[0].y + 32) / TXT_HEIGHT;
	next_pos_x = g_data.p_img->instances[0].x / TXT_WIDTH;
	f_x = g_data.p_img->instances[0].x;
	f_y = g_data.p_img->instances[0].y + 32;
	if (g_data.map[next_pos_y][next_pos_x] == '1')
		return ;
	if (g_data.map[next_pos_y][next_pos_x] == 'C'
		|| g_data.map[next_pos_y][next_pos_x] == 'W')
	{
		g_data.c_count--;
		g_data.map[next_pos_y][next_pos_x] = '0';
		render_floor(mlx, f_x, f_y);
		mlx_delete_image(mlx, g_data.p_img);
		init_player(mlx, f_x, f_y - 32);
	}
	g_data.n_moves++;
	ft_printf("number of moves = %d\n", g_data.n_moves);
	if (g_data.map[next_pos_y][next_pos_x] == 'E' && g_data.c_count == 0)
		free_and_exit(mlx);
	g_data.p_img->instances[0].y += 32;
}

void	player_move_right(mlx_t *mlx)
{
	int	next_pos_x;
	int	next_pos_y;
	int	f_x;
	int	f_y;

	next_pos_y = (g_data.p_img->instances[0].y) / TXT_HEIGHT;
	next_pos_x = (g_data.p_img->instances[0].x + 32) / TXT_WIDTH;
	f_x = g_data.p_img->instances[0].x + 32;
	f_y = g_data.p_img->instances[0].y;
	if (g_data.map[next_pos_y][next_pos_x] == '1')
		return ;
	if (g_data.map[next_pos_y][next_pos_x] == 'C'
		|| g_data.map[next_pos_y][next_pos_x] == 'W')
	{
		g_data.c_count--;
		g_data.map[next_pos_y][next_pos_x] = '0';
		render_floor(mlx, f_x, f_y);
		mlx_delete_image(mlx, g_data.p_img);
		init_player(mlx, f_x - 32, f_y);
	}
	g_data.n_moves++;
	ft_printf("number of moves = %d\n", g_data.n_moves);
	if (g_data.map[next_pos_y][next_pos_x] == 'E' && g_data.c_count == 0)
		free_and_exit(mlx);
	g_data.p_img->instances[0].x += 32;
}

void	player_move_left(mlx_t *mlx)
{
	int	next_pos_x;
	int	next_pos_y;
	int	f_x;
	int	f_y;

	next_pos_y = (g_data.p_img->instances[0].y) / TXT_HEIGHT;
	next_pos_x = (g_data.p_img->instances[0].x - 5) / TXT_WIDTH;
	f_x = g_data.p_img->instances[0].x - 32;
	f_y = g_data.p_img->instances[0].y;
	if (g_data.map[next_pos_y][next_pos_x] == '1')
		return ;
	if (g_data.map[next_pos_y][next_pos_x] == 'C'
		|| g_data.map[next_pos_y][next_pos_x] == 'W')
	{
		g_data.c_count--;
		g_data.map[next_pos_y][next_pos_x] = '0';
		render_floor(mlx, f_x, f_y);
		mlx_delete_image(mlx, g_data.p_img);
		init_player(mlx, f_x + 32, f_y);
	}
	g_data.n_moves++;
	ft_printf("number of moves = %d\n", g_data.n_moves);
	if (g_data.map[next_pos_y][next_pos_x] == 'E' && g_data.c_count == 0)
		free_and_exit(mlx);
	g_data.p_img->instances[0].x -= 32;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == 1)
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
	if (g_data.c_count == 0)
		update_chest(param);
}
