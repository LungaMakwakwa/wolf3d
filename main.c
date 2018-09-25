/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakwakw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:49:03 by lmakwakw          #+#    #+#             */
/*   Updated: 2018/09/14 13:40:28 by lmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		intialize_player(t_player *pos)
{
	pos->posx = 22;
	pos->posy = 12;
	pos->dirx = -1;
	pos->diry = 0;
	pos->planex = 0;
	pos->planey = 0.66;
	pos->time = 0;
	pos->oldtime = 0;
}

void		intialize_sdl(t_player *pos)
{
	pos->mywindow = SDL_CreateWindow("wolf3d@lmakwakw", 100,
		100, WIDTH, HEIGHT, 0);
	pos->myrenderer = SDL_CreateRenderer(pos->mywindow, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void		loops(t_player *pos, int game)
{
	SDL_Event	e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			game = 0;
		if (e.type == SDL_KEYUP)
			escape(e.key.keysym.sym, pos);
	}
}

void		end_program(t_player *pos)
{
	SDL_DestroyRenderer(pos->myrenderer);
	SDL_DestroyWindow(pos->mywindow);
}

int			main(int argc, char **argv)
{
	int			game;
	t_player	pos;

	if (argc == 2)
	{
		intialize_player(&pos);
		SDL_Init(0);
		intialize_sdl(&pos);
		pos = map_read(argv[1], pos);
		if (valid_border(pos, 0, 0) != 1)
			error_message();
		game = 1;
		while (game)
		{
			raycast(pos);
			SDL_RenderPresent(pos.myrenderer);
			loops(&pos, game);
		}
		end_program(&pos);
	}
	else
		ft_putendl("ERROR: Too many or Too few arguments");
	return (0);
}
