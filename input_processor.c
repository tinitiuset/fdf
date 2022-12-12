/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:16:31 by mvalient          #+#    #+#             */
/*   Updated: 2022/12/12 12:24:07 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line(char **line)
{
	static int	y = 0;
	int			x;

	x = 0;
	while (line[x])
	{
		if (*line[x] == 10)
		{
			y++;
			break;
		}
		ft_add_point(x, y , ft_atoi(line[x]));
		x++;
	}

}

void	read_file(char *file)
{
	char *line;
	int	fd;

	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		return ;
	line = get_next_line(fd);
	ft_draw_line(ft_split(line, 32));
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			ft_draw_line(ft_split(line, 32));
	}
	return ;
}

