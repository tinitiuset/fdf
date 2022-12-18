/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:47:50 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/18 14:22:16 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_add_pixel(t_pixel **list, int x, int y, int color)
{
	t_pixel	*new_pixel;
	t_pixel	*node;

	if (DEBUG)
		ft_printf("Pixel to be stored: %d,%d, Color: %X\n", x, y, color);
	new_pixel = malloc(sizeof(t_pixel));
	new_pixel->x = x;
	new_pixel->y = y;
	new_pixel->color = color;
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
