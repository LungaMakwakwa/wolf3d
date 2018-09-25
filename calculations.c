/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakwakw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:03:15 by lmakwakw          #+#    #+#             */
/*   Updated: 2018/09/13 14:03:28 by lmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ray_pos_dir(t_player *pos, int x)
{
	pos->camerax = 2 * x / (double)(WIDTH) - 1;
	pos->raydirx = pos->dirx + pos->planex * pos->camerax;
	pos->raydiry = pos->diry + pos->planey * pos->camerax;
}

void	basic_cal(t_player *pos)
{
	pos->mapx = (int)(pos->posx);
	pos->mapy = (int)(pos->posy);
	pos->deltadistx = fabs(1 / pos->raydirx);
	pos->deltadisty = fabs(1 / pos->raydiry);
}

void	side_dis_cal(t_player *pos)
{
	if (pos->raydirx < 0)
	{
		pos->stepx = -1;
		pos->sidedistx = (pos->posx - pos->mapx) * pos->deltadistx;
	}
	else
	{
		pos->stepx = 1;
		pos->sidedistx = (pos->mapx + 1.0 - pos->posx) * pos->deltadistx;
	}
	if (pos->raydiry < 0)
	{
		pos->stepy = -1;
		pos->sidedisty = (pos->posy - pos->mapy) * pos->deltadisty;
	}
	else
	{
		pos->stepy = 1;
		pos->sidedisty = (pos->mapy + 1.0 - pos->posy) * pos->deltadisty;
	}
}

void	next_square(t_player *pos)
{
	pos->hit = 0;
	while (pos->hit == 0)
	{
		if (pos->sidedistx < pos->sidedisty)
		{
			pos->sidedistx += pos->deltadistx;
			pos->mapx += pos->stepx;
			pos->side = 0;
		}
		else
		{
			pos->sidedisty += pos->deltadisty;
			pos->mapy += pos->stepy;
			pos->side = 1;
		}
		if (pos->myworld[pos->mapx][pos->mapy] > 0)
			pos->hit = 1;
	}
}

double	perpwall_cal(t_player *pos)
{
	if (pos->side == 0)
	{
		pos->perpwalldist = (pos->mapx - pos->posx +
		(1 - pos->stepx) / 2) / pos->raydirx;
	}
	else
	{
		pos->perpwalldist = (pos->mapy - pos->posy +
		(1 - pos->stepy) / 2) / pos->raydiry;
	}
	return (pos->perpwalldist);
}
