/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:22:34 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/21 12:52:37 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_add_point(t_point **list, int x, int y, int z)
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
	if (!(*list))
	{
		*list = new_point;
		return ;
	}
	node = *list;
	while (node->next)
		node = node->next;
	node->next = new_point;
}

void	ft_clear_point_list(t_point **point_list_head, void (*del)(void *))
{
	t_point	*about_to_del;

	while (*point_list_head)
	{
		about_to_del = *point_list_head;
		*point_list_head = (*point_list_head)->next;
		del(about_to_del);
	}
}
