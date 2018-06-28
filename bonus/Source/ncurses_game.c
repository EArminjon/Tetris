/*
** ncurses_game.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Feb 23 16:34:17 2017 Enguerrand Arminjon
** Last update Sat Mar 18 15:54:04 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include "my.h"
#include "tetris.h"
#include "global.h"
#include "my_error.h"

int	g_my_time;

int		next_fall_shape(char **tetri_map, t_tetris *tetris,
				t_fall *fall, t_shape *shape)
{
  if (tetris->first == 1)
    free_tab(fall->shape);
  if ((fall->shape = load_shape(fall, shape, tetris)) == NULL)
    return (ERROR);
  if ((tetri_map = load_shape_on_top(fall, tetri_map, tetris, 0)) == NULL)
    return (GAME_OVER);
  tetris->first = 1;
  return (0);
}

void		speed_of_the_game(t_tetris *tetris)
{
  if (g_my_time >= 10)
    {
      if (tetris->time->my_time - 60 > 0)
	tetris->time->my_time = tetris->time->my_time - 60;
      else if (tetris->time->my_time - 1 > 0)
	tetris->time->my_time = tetris->time->my_time - 1;
      g_my_time = 0;
    }
}

void		fall_one_line(char **tetri_map, t_tetris *tetris)
{
  if (tetris->time->now - tetris->time->time_level > tetris->time->my_time)
    {
      tetri_map = fall_shape_one_line(tetri_map, tetris);
      tetris->time->time_level = clock() / 1000;
      tetris->time->now = clock() / 1000;
    }
}

int		start_tetris_game(char **tetri_map, t_shape *shape,
				  t_tetris *tetris, int ret)
{
  char		*s;
  t_fall	fall;

  fall.shape = NULL;
  tetris->time->my_time = 1000 - tetris->level * 40;
  tetris->time->start = clock() / 1000;
  tetris->time->time_level = clock() / 1000;
  while (check_game(tetri_map) == 0)
    {
      if ((s = press_any_key(tetris->keys, 1, 0, 0)) != NULL
	  && my_strcmp(s, IOCTL) == 0)
	return (84);
      if (tetris->f_next == NEXT_FALL_SHAPE)
	if ((ret = next_fall_shape(tetri_map, tetris, &fall, shape)) != 0)
	  return (ret);
      display_game(tetri_map, tetris, 0, 1);
      if ((tetri_map = game_cmds(tetri_map, tetris, &fall, s)) == NULL)
	return (0);
      tetris->time->now = clock() / 1000;
      fall_one_line(tetri_map, tetris);
      if (tetris->f_next == NEXT_FALL_SHAPE)
	tetri_map = convert_map(tetri_map);
      tetri_map = my_delete_line(tetri_map, tetris->row, tetris, 0);
    }
  return (SUCCESS);
}

int	display_ncurses(t_shape *shape, t_tetris *tetris)
{
  int	nb;
  char	**tetri_map;

  tetris->f_next = 0;
  g_my_time = 0;
  tetris->level = my_getnbr(tetris->num);
  tetris->line = 0;
  tetri_map = NULL;
  if ((initscr()) == NULL
      || ((tetris->time = malloc(sizeof(*tetris->time))) == NULL))
    return (84);
  curs_set(0);
  clear();
  noecho();
  keypad(stdscr, TRUE);
  if ((display_menu(tetris)) == 1)
    return (destroy_music(tetris));
  tetri_map = init_map_game(tetri_map, tetris, 0);
  display_game(NULL, tetris, 0, 0);
  nb = start_tetris_game(tetri_map, shape, tetris, 0);
  nb = display_game_over_file_leaderboard(tetris, nb);
  free_tab(tetri_map);
  clear();
  endwin();
  return (nb);
}
