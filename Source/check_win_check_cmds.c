/*
** check_win_check_cmds.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Mar  7 10:08:09 2017 Enguerrand Arminjon
** Last update Sat Mar 18 16:14:09 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"
#include "my_error.h"
#include "global.h"

int	check_game(char **map)
{
  int	j;
  int	empty_col;

  j = 1;
  empty_col = 0;
  while (map[1][j + 1] != '\0')
    {
      if (map[1][j] == '.' || map[1][j] == ' '
	  || (map[1][j] >= '0' && map[1][j] <= '9'))
	empty_col++;
      j++;
    }
  if (empty_col == 0)
    return (GAME_OVER);
  return (SUCCESS);
}

char	**my_drop_shape(char **tetri_map, t_tetris *tetris)
{
  while (tetris->f_next == 1)
    tetri_map = fall_shape_one_line(tetri_map, tetris);
  return (tetri_map);
}

void	my_pause_cmds(t_tetris *tetris)
{
  char	*p;
  int	i;

  i = 0;
  p = NULL;
  p = press_any_key(1, 0, 1, 0);
  while (i == 0)
    {
      if (p != NULL)
	{
	  if ((my_strstr(p, tetris->t_debug->pause)) == 0)
	    i = 1;
	}
      p = press_any_key(0, 0, 1, 0);
    }
  p = press_any_key(1, 0, 1, 0);
}

char	**game_cmds(char **tetri_map, t_tetris *tetris, t_fall *fall, char *s)
{
  tetris->keys = 1;
  if (s == NULL)
    tetris->keys = 0;
  else if ((my_strstr(s, tetris->t_debug->quit)) == 0)
    {
      tetris->keys = -2;
      return (NULL);
    }
  else if ((my_strstr(s, tetris->t_debug->left)) == 0)
    tetri_map = move_my_shape_left(tetri_map, tetris, fall);
  else if ((my_strstr(s, tetris->t_debug->right)) == 0)
    tetri_map = move_my_shape_right(tetri_map, tetris, fall);
  else if ((my_strstr(s, tetris->t_debug->top)) == 0)
    tetri_map = my_rotate_shape(tetri_map, tetris, fall);
  else if ((my_strstr(s, tetris->t_debug->drop)) == 0)
    tetri_map = my_drop_shape(tetri_map, tetris);
  else if ((my_strstr(s, tetris->t_debug->pause)) == 0)
    my_pause_cmds(tetris);
  else
    tetris->keys = 0;
  return (tetri_map);
}
