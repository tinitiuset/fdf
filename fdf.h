/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:41:23 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/21 13:30:50 by mvalient         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080
# define MULTIPLIER 5
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
}				t_pixel;

typedef struct s_line
{
	int	beginx;
	int	endx;
	int	beginy;
	int	endy;
	int	color;
}				t_line;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_point		*points;
}				t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

t_point	*ft_read_file(char *file);
t_pixel	ft_point_to_pixel(t_point *point);
void	ft_add_point(t_point **list, int x, int y, int z);
void	ft_clear_point_list(t_point **lst, void (*del)(void *));
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	ft_put_lines(t_img *data, t_mlx *mlx);

#endif
