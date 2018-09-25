/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakwakw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:01:48 by lmakwakw          #+#    #+#             */
/*   Updated: 2018/09/17 10:32:33 by lmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	void	set_col(t_colpik *mypik, int c1, int c2, int c3)
{
	mypik->r = c1;
	mypik->g = c2;
	mypik->b = c3;
}

t_colpik		colourpick(t_player *pos)
{
	t_colpik mypik;

	mypik.r = 0xff;
	mypik.g = 0x00;
	mypik.b = 0xff;
	if (pos->side == 1)
	{
		if (pos->raydiry > 0)
			set_col(&mypik, 0x5b, 0xff, 0x84);
		else
			set_col(&mypik, 0x3b, 0xc6, 0x9a);
	}
	else if (pos->side == 0)
	{
		if (pos->raydirx > 0)
			set_col(&mypik, 0xff, 0x32, 0x32);
		else
			set_col(&mypik, 0x84, 0x00, 0x32);
	}
	return (mypik);
}
