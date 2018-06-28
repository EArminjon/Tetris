/*
** delete_line.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Mar  1 10:58:21 2017 Enguerrand Arminjon
** Last update Wed Mar 15 15:48:42 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "global.h"

char		**replace(char **map, int i)
{
  int		j;

  j = 1;
  while (map[i][j + 1] != '\0')
    {
      map[i][j] = '.';
      j++;
    }
  return (map);
}

char		**put_down(char **map, int i)
{
  int		j;

  while (i - 1 > 0)
    {
      j = 1;
      while (map[i][j + 1] != '\0')
	{
	  map[i][j] = map[i - 1][j];
	  map[i - 1][j] = '.';
	  j++;
	}
      --i;
    }
  return (map);
}

char		**my_delete_line(char **map, int line, t_tetris *tetris, int i)
{
  int		j;
  int		k;

  while (++i <= line)
    {
      k = 0;
      j = -1;
      while (map[i][++j] != '\0')
	{
	  if (map[i][j] == '.' || map[i][j] == ' ' || map[i][j] == '_'
	      || (map[i][j] >= '0' && map[i][j] <= '9'))
	    k++;
	}
      if (k == 0)
	{
	  tetris->score = tetris->score + 10 + (2 * j);
	  tetris->line++;
	  g_my_time++;
	  map = replace(map, i);
	  map = put_down(map, i);
	}
    }
  speed_of_the_game(tetris);
  return (map);
}
