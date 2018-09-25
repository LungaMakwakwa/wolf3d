/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakwakw <lmakwakw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:49:48 by lmakwakw          #+#    #+#             */
/*   Updated: 2018/09/13 12:05:09 by lmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		button(int but, t_map *head)
{
	(void)but;
	(void)head;
	exit(0);
}

int		escape(int keycode, t_player *pos)
{
	if (keycode == SDLK_ESCAPE)
		exit(1);
	if (keycode == SDLK_w)
		moveup(pos);
	if (keycode == SDLK_s)
		movedown(pos);
	if (keycode == SDLK_a)
		moveleft(pos);
	if (keycode == SDLK_d)
		moveright(pos);
	return (0);
}
