/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:41:23 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/18 14:22:16 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fcntl.h"
# include "math.h"
# include "mlx.h"

# include "./libft_extra/ft_printf/ft_printf.h"
# include "./libft_extra/get_next_line/get_next_line.h"
# include "./libft_extra/libft/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define MULTIPLIER 50
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define DEBUG 1

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}				t_point;

typedef struct s_pixel
{
	int				x;
	int				y;
	int				color;
	struct s_pixel	*next;
}				t_pixel;

typedef struct s_object_data
{
	t_pixel			*pixels;
	t_point			*points;
}				t_object_data;

t_point	*ft_read_file(char *file);
t_pixel	*ft_points_to_pixels(t_point *point_list_head);
void	ft_add_point(t_point **list, int x, int y, int z);
void	ft_add_pixel(t_pixel **list, int x, int y, int color);

#endif
