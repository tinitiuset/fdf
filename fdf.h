/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:41:23 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/20 19:36:39 by mvalient         ###   ########.fr       */
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
# define MULTIPLIER 30
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

typedef struct s_line
{
	int	beginx;
	int	endx;
	int	beginy;
	int	endy;
	int	color;
}				t_line;

typedef struct s_object_data
{
	t_pixel			*pixels;
	t_point			*points;
}				t_object_data;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

t_point	*ft_read_file(char *file);
t_pixel	*ft_points_to_pixels(t_point *point_list_head);
void	ft_add_point(t_point **list, int x, int y, int z);
void	ft_add_pixel_to_list(t_pixel **list, t_pixel pixel);
void	ft_put_pixel(t_data *img, int x, int y, int color);
void	ft_put_pixels(t_data *img, t_pixel *pixel_list_head);
void	ft_put_lines(t_data *img, t_pixel *pixel_list_head);

#endif
