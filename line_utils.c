/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:46:06 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/20 18:30:38 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_line(t_data *data, t_line line)
{
	int		pixels;
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;

	delta_x = line.endx - line.beginx;
	delta_y = line.endy - line.beginy;
	pixels = (int) sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	delta_x = delta_x / pixels;
	delta_y = delta_y / pixels;
	pixel_x = line.beginx;
	pixel_y = line.beginy;
	while (pixels)
	{
		ft_put_pixel(data, (int) pixel_x, (int) pixel_y, line.color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
	if (DEBUG)
		ft_printf("Drawing line from %d, %d to %d, %d. Color: %X\n",
			line.beginx, line.beginy, line.endx, line.endy, line.color);
}

void	ft_put_lines(t_data *data, t_pixel *pixel_list_head)
{
	t_pixel	*current_pixel;
	t_line	current_line;

	current_pixel = pixel_list_head;
	while (current_pixel && current_pixel->next)
	{
		if (current_pixel->x < current_pixel->next->x)
		{
			current_line.beginx = current_pixel->x;
			current_line.beginy = current_pixel->y;
			current_line.endx = current_pixel->next->x;
			current_line.endy = current_pixel->next->y;
			current_line.color = 0xFFFFFF;
			ft_put_line(data, current_line);
		}
		current_pixel = current_pixel->next;
	}
}
