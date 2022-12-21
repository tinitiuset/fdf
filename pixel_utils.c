/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:47:50 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/20 19:41:16 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_add_pixel_to_list(t_pixel **list, t_pixel pixel)
{
	t_pixel	*new_pixel;
	t_pixel	*node;

	if (DEBUG)
		ft_printf("Pixel to be stored: %d,%d, Color: %X\n",
			pixel.x, pixel.y, pixel.color);
	new_pixel = malloc(sizeof(t_pixel));
	new_pixel->x = pixel.x;
	new_pixel->y = pixel.y;
	new_pixel->color = pixel.color;
	new_pixel->next = NULL;
	if (!(*list))
	{
		*list = new_pixel;
		return ;
	}
	node = *list;
	while (node->next)
		node = node->next;
	node->next = new_pixel;
}

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
	if (DEBUG)
		ft_printf("Setting pixel X: %d, Y: %d, Color: %X\n", x, y, color);
}

void	ft_put_pixels(t_img *img, t_pixel *pixel_list_head)
{
	t_pixel	*current_pixel;

	current_pixel = pixel_list_head;
	while (current_pixel)
	{
		ft_put_pixel(img,
			current_pixel->x, current_pixel->y, current_pixel->color);
		current_pixel = current_pixel->next;
	}
}
