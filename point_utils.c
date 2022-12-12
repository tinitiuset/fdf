/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:22:34 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/10 19:38:24 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point *points;

void	ft_add_point(int x, int y, int z)
{
	t_point	*new_point;
	t_point	*node;

	if (DEBUG)
		ft_printf("Point to be stored: %d,%d,%d\n", x, y, z);
	new_point = malloc(sizeof(t_point));
	new_point->x = x;
	new_point->y = y;
	new_point->z = z;
	new_point->next = NULL;
	if (!points)
	{
		points = new_point;
		return ;
	}
	node = points;
	while (node->next)
		node = node->next;
	node->next = new_point;
}