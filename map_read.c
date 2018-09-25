/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakwakw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:50:30 by lmakwakw          #+#    #+#             */
/*   Updated: 2018/09/13 12:00:38 by lmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		free_array(void **array)
{
	int n;

	n = 0;
	while (array[n] != NULL)
	{
		free(array[n]);
		n++;
	}
	free(array);
}

t_player	map_read(char *file, t_player pos)
{
	t_read	read;
	int		head;

	head = 0;
	read.fd = check_map(file);
	pos.newread.py = 0;
	while ((read.ret = get_next_line(read.fd, &read.line)) > 0)
	{
		pos.newread.px = 0;
		pos.newread.split = ft_strsplit(read.line, ' ');
		while (pos.newread.split[pos.newread.px] != NULL)
		{
			pos.myworld[pos.newread.px][pos.newread.py] =
				ft_atoi(pos.newread.split[pos.newread.px]);
			pos.newread.px += 1;
		}
		pos.newread.py += 1;
		free(read.line);
		free_array((void**)pos.newread.split);
		head = 1;
	}
	pos.rows = pos.newread.py;
	pos.cols = pos.newread.px;
	empty_map(head);
	return (pos);
}
