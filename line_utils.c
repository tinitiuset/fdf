/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:46:06 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/20 21:06:12 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_line(t_data *data, t_line *line)
{
	int		pixels;
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;

	if (!line)
		return ;
	delta_x = line->endx - line->beginx;
	delta_y = line->endy - line->beginy;
	pixels = (int) sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	delta_x = delta_x / pixels;
	delta_y = delta_y / pixels;
	pixel_x = line->beginx;
	pixel_y = line->beginy;
	while (pixels)
	{
		ft_put_pixel(data, (int) pixel_x, (int) pixel_y, line->color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
	free(line);
}

static t_line	*ft_horizontal_line(t_point *point)
{
	t_line	*line;
	t_pixel	pixel;

	if ((point && point->next) && point->y == point->next->y)
	{
		line = malloc(sizeof(t_line));
		pixel = ft_point_to_pixel(point);
		line->beginx = pixel.x;
		line->beginy = pixel.y;
		pixel = ft_point_to_pixel(point->next);
		line->endx = pixel.x;
		line->endy = pixel.y;
		line->color = pixel.color;
		return (line);
	}
	return (NULL);
}

static t_line	*ft_vertical_line(t_point *point)
{
	t_point	*next_point;
	t_line	*line;
	t_pixel	pixel;

	if (!point->next)
		return (NULL);
	next_point = point->next;
	while (point->x != next_point->x)
	{
		if (next_point->next)
			next_point = next_point->next;
		else
			break ;
	}
	line = malloc(sizeof(t_line));
	pixel = ft_point_to_pixel(point);
	line->beginx = pixel.x;
	line->beginy = pixel.y;
	pixel = ft_point_to_pixel(next_point);
	line->endx = pixel.x;
	line->endy = pixel.y;
	line->color = pixel.color;
	return (line);
}

void	ft_put_lines(t_data *data, t_point *current_point)
{
	while (current_point)
	{
		ft_put_line(data, ft_horizontal_line(current_point));
		ft_put_line(data, ft_vertical_line(current_point));
		current_point = current_point->next;
	}
}
