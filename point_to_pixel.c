/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:36:10 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/20 19:35:14 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pixel	ft_isometric(t_point *point)
{
	double	x;
	double	y;
	t_pixel pixel;

	x = (point->x - point->y) * cos(0.523599);
	y = (-(point->z)) + (point->x + point->y) * sin(0.523599);
	x = WIDTH / 2 + (x * MULTIPLIER);
	y = HEIGHT / 2 + (y * MULTIPLIER);
	pixel.x = (int) x;
	pixel.y = (int) y;
	pixel.color = 0xFFFFFF;
	pixel.next = NULL;
	return (pixel);
}

t_pixel	ft_point_to_pixel(t_point *point)
{
	return (ft_isometric(point));
}

t_pixel	*ft_points_to_pixels(t_point *point_list_head)
{
	t_pixel	*pixel_list;
	t_point	*current_point;

	pixel_list = NULL;
	current_point = point_list_head;
	while (current_point)
	{
		ft_add_pixel_to_list(&pixel_list, ft_point_to_pixel(current_point));
		current_point = current_point->next;
	}
	return (pixel_list);
}
