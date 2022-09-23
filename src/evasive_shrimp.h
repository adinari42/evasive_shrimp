/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evasive_shrimp.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:20:08 by adinari           #+#    #+#             */
/*   Updated: 2022/09/22 23:27:33 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVASIVE_SHRIMP_H
# define EVASIVE_SHRIMP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "../codam_MLX/include/MLX42/MLX42.h"
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"

# define TXT_WIDTH	32
# define TXT_HEIGHT	32
# define WIDTH 		1000
# define HEIGHT 		1000

typedef struct s_data
{
	void			*img;
	mlx_image_t		*p_img;
	mlx_image_t		*c_img;
	mlx_texture_t	*img2[3];
	char			*addr;
	char			*relative_path;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				c_count;
	int				e_count;
	int				p_count;
	int				img_width;
	int				img_height;
	char			**map;
	int				end;
	int				n_moves;
	int				dim[2];
	int				player_x;
	int				player_y;
}					t_data;

typedef struct s_line
{
	char			*line;
	int				last_width;
	char			*last_line;
}				t_line;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_wall
{
	int	x;
	int	y;
}				t_wall;

t_data	g_data;

int32_t	main(int argc, char **argv);
void	init_player(mlx_t *mlx, int x, int y);
void	free_and_exit(mlx_t *mlx);
void	open_chest(mlx_t *mlx, int *x, int y);
void	get_dimensions(int dim[2], char *path);
void	perror_exit(int error);
char	*init_line(int fd);
void	update_chest(void *param);
int		save_map(int dim[2], char *path);
void	render_map(mlx_t *mlx, char *path);
void	render_texture(mlx_t *mlx, char *path, int *x, int y);
void	render_floor(mlx_t *mlx, int x, int y);
void	key_hook(mlx_key_data_t keydata, void *param);
int		path_check(void);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif