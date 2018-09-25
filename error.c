/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakwakw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:50:50 by lmakwakw          #+#    #+#             */
/*   Updated: 2018/09/17 10:36:06 by lmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		valid_border(t_player pos, int i, int j)
{
	i = 0;
	j = -1;
	while (++j < pos.cols - 1)
		if (pos.myworld[i][j] < 1)
			return (0);
	j = -1;
	i = pos.rows - 1;
	while (++j < pos.cols - 1)
		if (pos.myworld[i][j] < 1)
			return (0);
	j = 0;
	i = -1;
	while (++i < pos.rows)
		if (pos.myworld[i][j] != 1)
			return (0);
	j = pos.cols - 1;
	i = -1;
	while (++i < pos.rows - 1)
		if (pos.myworld[i][j] != 1)
			return (0);
	return (1);
}

void	empty_map(int head)
{
	if (head == 0)
	{
		ft_putendl("Error: File Is EMPTY");
		exit(1);
	}
}

int		check_map(char *file)
{
	int		fd;
	char	*check;

	check = ft_strrchr(file, '.');
	if (check == NULL)
	{
		ft_putendl("ERROR: Invalid file");
		exit(1);
	}
	if ((ft_strcmp(check, ".wolf") != 0))
	{
		ft_putendl("ERROR: Invalid file");
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR: On File Opening");
		exit(1);
	}
	return (fd);
}

void	error_message(void)
{
	ft_putendl("ERROR: No borders");
	exit(1);
}
