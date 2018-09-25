/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakwakw <lmakwakw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:50:41 by lmakwakw          #+#    #+#             */
/*   Updated: 2018/09/13 13:49:52 by lmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	lines(t_player *pos)
{
	pos->lineheight = (int)(HEIGHT / pos->perpwalldist);
	pos->drawstart = -pos->lineheight / 2 + HEIGHT / 2;
	if (pos->drawstart < 0)
		pos->drawstart = 0;
	pos->drawend = pos->lineheight / 2 + HEIGHT / 2;
	if (pos->drawend >= HEIGHT)
		pos->drawend = HEIGHT - 1;
}

void	movement_cal(t_player *pos)
{
	pos->oldtime = clock();
	pos->time = clock();
	pos->frametime = ((double)(pos->time - pos->oldtime)) / CLOCKS_PER_SEC;
	pos->movspeed = pos->frametime * 5.0;
	pos->rotspeed = pos->frametime * 10.0;
}

void	draw_sdl(t_player *pos, int x, int y)
{
	t_colpik m_p;

	pos->ceiling = (HEIGHT / 2) - HEIGHT / pos->perpwalldist;
	pos->floors = HEIGHT - pos->ceiling;
	m_p = colourpick(pos);
	if (y <= pos->ceiling)
	{
		SDL_SetRenderDrawColor(pos->myrenderer, 0x7c, 0xb2, 0xFF, 0xFF);
		SDL_RenderDrawPoint(pos->myrenderer, x, y);
	}
	else if (y > pos->ceiling && y < pos->floors)
	{
		SDL_SetRenderDrawColor(pos->myrenderer, m_p.r, m_p.g, m_p.b, 0xFF);
		SDL_RenderDrawPoint(pos->myrenderer, x, y);
	}
	else
	{
		SDL_SetRenderDrawColor(pos->myrenderer, 0x38, 0x35, 0x35, 0xFF);
		SDL_RenderDrawPoint(pos->myrenderer, x, y);
	}
}

void	raycast(t_player pos)
{
	int x;
	int y;

	x = 0;
	while (x++ < WIDTH)
	{
		ray_pos_dir(&pos, x);
		basic_cal(&pos);
		side_dis_cal(&pos);
		next_square(&pos);
		pos.perpwalldist = perpwall_cal(&pos);
		lines(&pos);
		movement_cal(&pos);
		y = 0;
		while (y++ < HEIGHT)
		{
			draw_sdl(&pos, x, y);
		}
	}
}
