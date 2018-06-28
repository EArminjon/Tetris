/*
** my_rotate_shape.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Mar  1 09:21:40 2017 Enguerrand Arminjon
** Last update Tue Mar 14 14:58:43 2017 Enguerrand Arminjon
*/

#include "tetris.h"
#include "my.h"

char		**convert_for_rotate(char **copy)
{
  int		i;
  int		j;

  i = 0;
  while (copy[i] != NULL)
    {
      j = 0;
      while (copy[i][j] != '\0')
	{
	  if (copy[i][j] ==  ' ' || (copy[i][j] >= '0' && copy[i][j] <= '9'))
	    copy[i][j] = '.';
	  j++;
	}
      i++;
    }
  return (copy);
}

int		find_last_row_shape(char **tetri_map, int row_map)
{
  int		i;
  int		j;
  int		last_row;

  i = row_map;
  last_row = 0;
  while (i > 0 && last_row == 0)
    {
      j = 1;
      while (tetri_map[i][j + 1] != '\0' && last_row == 0)
	{
	  if (tetri_map[i][j] ==  ' '
	      || (tetri_map[i][j] >= '0' && tetri_map[i][j] <= '9'))
	    last_row = i;
	  j++;
	}
      i--;
    }
  return (last_row);
}

int		find_first_row_shape(char **tetri_map)
{
  int		i;
  int		j;
  int		first_row;

  i = 0;
  first_row = 0;
  while (tetri_map[i] != NULL && first_row == 0)
    {
      j = 1;
      while (tetri_map[i][j + 1] != '\0' && first_row == 0)
	{
	  if (tetri_map[i][j] ==  ' '
	      || (tetri_map[i][j] >= '0' && tetri_map[i][j] <= '9'))
	    first_row = i;
	  j++;
	}
      i++;
    }
  return (first_row);
}

int		find_first_col_shape(char **tetri_map)
{
  int		first_col;
  int		i;
  int		j;

  i = 1;
  j = 1;
  first_col = 0;
  while (tetri_map[i][j + 1] != '\0' && first_col == 0)
    {
      i = 1;
      while (tetri_map[i + 1] != NULL && first_col == 0)
	{
	  if (tetri_map[i][j] ==  ' '
	      || (tetri_map[i][j] >= '0' && tetri_map[i][j] <= '9'))
	    first_col = j;
	  i++;
	}
      j++;
    }
  return (first_col);
}

int		find_last_col_shape(char **tetri_map, t_tetris *tetris)
{
  int		last_col;
  int		i;
  int		j;

  i = 1;
  j = tetris->t_debug->col;
  last_col = 0;
  while (j > 0 && last_col == 0)
    {
      i = 1;
      while (tetri_map[i + 1] != NULL && last_col == 0)
	{
	  if (tetri_map[i][j] ==  ' '
	      || (tetri_map[i][j] >= '0' && tetri_map[i][j] <= '9'))
	    last_col = j;
	  i++;
	}
      j--;
    }
  return (last_col);
}
