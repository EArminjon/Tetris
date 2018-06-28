/*
** fall_shape.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Mar  1 10:55:09 2017 Enguerrand Arminjon
** Last update Thu Mar 16 09:40:58 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "global.h"

int	check_fall(char **tetri_map, int size, t_tetris *tetris)
{
  int	j;
  int	i;

  i = -1;
  while (tetri_map[++i] != NULL)
    {
      j = 1;
      while (tetri_map[i][j + 1] != '\0')
	{
	  if (tetri_map[i][j] == ' ' || (tetri_map[i][j] >= '0'
					 && tetri_map[i][j] <= '9'))
	    {
	      if ((i - 1 == size)
		  || (tetri_map[i + 1][j] != '.' && tetri_map[i + 1][j] != ' '
		      && tetri_map[i + 1][j] != '_' &&
		      (tetri_map[i + 1][j] < '0' || tetri_map[i + 1][j] > '9')))
		{
		  tetris->f_next = 0;
		  return (1);
		}
	    }
	  j++;
	}
    }
  return (0);
}

char	**fall_shape_one_line(char **tetri_map, t_tetris *tetris)
{
  int	i;
  int	j;
  int	nb;

  i = tetris->t_debug->row;
  nb = check_fall(tetri_map, tetris->t_debug->row - 1, tetris);
  if (nb == 0)
    {
      while (--i > 0)
	{
	  j = 0;
	  while (tetri_map[i][++j + 1] != '\0')
	    if (tetri_map[i][j] == ' ' || (tetri_map[i][j] >= '0'
					   && tetri_map[i][j] <= '9'))
	      {
		tetri_map[i + 1][j] = tetri_map[i][j];
		tetri_map[i][j] = '.';
	      }
	}
    }
  return (tetri_map);
}
