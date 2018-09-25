/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakwakw <lmakwakw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:50:01 by lmakwakw          #+#    #+#             */
/*   Updated: 2018/09/17 10:34:18 by lmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "/goinfre/lmakwakw/.brew/include/SDL2/SDL.h"
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# define WIDTH 800
# define HEIGHT 600
# define COL_BLUE 0x0061ff
# define COL_RED 0xff0000
# define COL_GREEN 0xa0ffa6
# define COL_WHITE 0xffffff
# define COL_BLACK 0x000000

typedef	struct		s_colpik
{
	int				r;
	int				g;
	int				b;
}					t_colpik;

typedef struct		s_read
{
	int				fd;
	int				ret;
	int				px;
	int				py;
	char			*line;
	char			**split;
}					t_read;

typedef	struct		s_player
{
	int				fd;
	int				stepx;
	int				stepy;
	int				hit;
	int				mapx;
	int				mapy;
	int				myworld[600][600];
	int				rows;
	int				cols;
	int				end;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				ceiling;
	int				floors;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			deltadistx;
	double			deltadisty;
	double			frametime;
	double			movspeed;
	double			rotspeed;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			perpwalldist;
	clock_t			time;
	clock_t			oldtime;
	t_colpik		colour;
	t_read			newread;
	SDL_Window		*mywindow;
	SDL_Renderer	*myrenderer;
}					t_player;

typedef	struct		s_map
{
	struct s_read	run;
	struct s_map	*next;
}					t_map;

int					check_map(char *file);
int					escape(int keycode, t_player *pos);
int					valid_border(t_player pos, int i, int j);
void				empty_map(int head);
void				raycast(t_player pos);
void				stepforward(t_player *pos);
void				moveup(t_player *pos);
void				movedown(t_player *pos);
void				moveright(t_player *pos);
void				moveleft(t_player *pos);
void				step(t_player pos);
void				ray_pos_dir(t_player *pos, int x);
void				basic_cal(t_player *pos);
void				side_dis_cal(t_player *pos);
void				next_square(t_player *pos);
void				lines(t_player *pos);
void				movement_cal(t_player *pos);
void				draw_sdl(t_player *pos, int x, int y);
void				raycast(t_player pos);
void				intialize_sdl(t_player *pos);
void				error_message(void);
double				perpwall_cal(t_player *pos);
t_colpik			side_y(t_player *pos);
t_colpik			side_x(t_player *pos);
t_colpik			colourpick(t_player *pos);
t_player			map_read(char *file, t_player pos);

#endif
