/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:17:56 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/21 13:04:38 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	clear_mem(t_mlx *mlx)
{
	ft_clear_point_list(&mlx->points, free);
	free(mlx->mlx);
	free(mlx);
	return (EXIT_SUCCESS);
}

static int	key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = param;
	ft_printf("KEY PRESSED: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(clear_mem(mlx));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx			*mlx;
	t_img			img;

	(void)argc;
	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "fdf");
	img.img = mlx_new_image(mlx->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx->points = ft_read_file(argv[1]);
	ft_put_lines(&img, mlx->points);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img.img, 0, 0);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->mlx);
	return (EXIT_SUCCESS);
}
