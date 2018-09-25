/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakwakw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:55:41 by lmakwakw          #+#    #+#             */
/*   Updated: 2018/09/14 12:08:34 by lmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	moveup(t_player *pos)
{
	if (pos->myworld[(int)(pos->posx + pos->dirx)][(int)(pos->posy)] == 0)
		pos->posx += pos->dirx;
	if (pos->myworld[(int)(pos->posx)][(int)(pos->posy + pos->diry)] == 0)
		pos->posy += pos->diry;
}

void	movedown(t_player *pos)
{
	if ((pos->myworld[(int)(pos->posx - pos->dirx)][(int)(pos->posy)]) == 0)
		pos->posx -= pos->dirx;
	if ((pos->myworld[(int)(pos->posx)][(int)(pos->posy - pos->diry)]) == 0)
		pos->posy -= pos->diry;
}

void	moveleft(t_player *pos)
{
	double	olddirx;

	pos->rotspeed = 0.174533;
	olddirx = pos->dirx;
	pos->dirx = pos->dirx * cos(pos->rotspeed) -
		pos->diry * sin(pos->rotspeed);
	pos->diry = olddirx * sin(pos->rotspeed) +
		pos->diry * cos(pos->rotspeed);
	pos->planex = pos->planex * cos(pos->rotspeed) -
		pos->planey * sin(pos->rotspeed);
	pos->planey = pos->planex * sin(pos->rotspeed) +
		pos->planey * cos(pos->rotspeed);
}

void	moveright(t_player *pos)
{
	double	olddirx;

	pos->rotspeed = 0.174533;
	olddirx = pos->dirx;
	pos->dirx = pos->dirx * cos(-pos->rotspeed) -
		pos->diry * sin(-pos->rotspeed);
	pos->diry = olddirx * sin(-pos->rotspeed) +
		pos->diry * cos(pos->rotspeed);
	pos->planex = pos->planex * cos(-pos->rotspeed) -
		pos->planey * sin(-pos->rotspeed);
	pos->planey = pos->planex * sin(-pos->rotspeed) +
		pos->planey * cos(-pos->rotspeed);
}
