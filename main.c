/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:17:56 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/18 20:20:37 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	t_object_data	object_data;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	object_data.points = ft_read_file(argv[1]);
	object_data.pixels = ft_points_to_pixels(object_data.points);
	ft_put_pixel_list(&img, object_data.pixels);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
