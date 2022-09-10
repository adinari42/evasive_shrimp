/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evasive_shrimp.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:20:08 by adinari           #+#    #+#             */
/*   Updated: 2022/09/08 20:21:18 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVASIVE_SHRIMP_H
# define EVASIVE_SHRIMP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "codam_MLX/include/MLX42/MLX42.h"
# include "gnl/get_next_line.h"

#define TXT_WIDTH	32
#define TXT_HEIGHT	32

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	char	*relative_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		C_count;
	int		img_width;
	int		img_height;
	char 	**map;
	int		end;
	int		n_moves;
	int		player_x;
	int		player_y;
}				t_data;

t_data	g_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_wall
{
	int	x;
	int	y;
}				t_wall;

int		main(void);
// char	*get_next_line(int fd);

#endif