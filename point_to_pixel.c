/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:36:10 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/18 14:18:17 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_isometric(t_pixel **pixel_list, t_point *point)
{
	int	x;
	int	y;

	x = (int)((point->x - point->y) * cos(0.523599));
	y = (int)(-(point->z) + (point->x + point->y) * sin(0.523599));
	ft_add_pixel(&*pixel_list, x, y, 0xFFFFFF);
}

t_pixel	*ft_points_to_pixels(t_point *point_list_head)
{
	t_pixel	*pixel_list;
	t_point	*current_point;

	pixel_list = NULL;
	current_point = point_list_head;
	while (current_point)
	{
		ft_isometric(&pixel_list, current_point);
		current_point = current_point->next;
	}
	return (pixel_list);
}