/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:41:23 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/10 19:29:48 by mvalient         ###   ########.fr       */
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

void	read_file(char *file);
void	ft_add_point(int x, int y, int z);

#endif
