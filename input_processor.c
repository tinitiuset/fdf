/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:16:31 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/18 14:15:15 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_store_line(char **line, t_point **list)
{
	static int	y = 0;
	int			x;

	x = 0;
	while (line[x])
	{
		ft_add_point(&*list, x, y, ft_atoi(line[x]));
		x++;
	}
	y++;
}

t_point	*ft_read_file(char *file)
{
	t_point	*point_list;
	char	*line;
	int		fd;

	point_list = NULL;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	ft_store_line(ft_split(line, 32), &point_list);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_store_line(ft_split(line, 32), &point_list);
	}
	return (point_list);
}
