/*
** build_convert_map.c for  in /home/armin.pc/delivery/PSU_2016_tetris/Source
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Mar  7 10:17:51 2017 Enguerrand Arminjon
** Last update Thu Mar  9 10:30:46 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

char	**convert_map(char **tetri_map)
{
  int	i;
  int	j;

  i = 1;
  while (tetri_map[i + 1] != NULL)
    {
      j = 1;
      while (tetri_map[i][j + 1] != '\0')
	{
	  if (tetri_map[i][j] >= '0' && tetri_map[i][j] <= '9')
	    tetri_map[i][j] = tetri_map[i][j] + 16;
	  else if (tetri_map[i][j] == ' ')
	    tetri_map[i][j] = '_';
	  j++;
	}
      i++;
    }
  return (tetri_map);
}

char	**init_map_game(char **map, t_debug *t_debug, int j)
{
  int	i;

  i = -1;
  if ((map = malloc_tab(map, t_debug->row + 2, t_debug->col + 2)) == NULL)
    return (NULL);
  while (++i < t_debug->row + 2)
    {
      map[i][0] = '|';
      map[i][t_debug->col + 1] = '|';
      map[i][t_debug->col + 2] = '\0';
      j = 1;
      while (j < t_debug->col + 1)
	{
	  if (i == 0 || i == t_debug->row + 1)
	    map[i][j++] = '=';
	  else
	    map[i][j++] =  '.';
	}
    }
  map[0][0] = '/';
  map[0][t_debug->col + 1] = '\\';
  map[t_debug->row + 1][0] = '\\';
  map[t_debug->row + 1][t_debug->col + 1] = '/';
  return (map);
}
