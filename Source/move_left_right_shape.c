/*
** move_left_right_shape.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sun Feb 26 09:47:39 2017 Enguerrand Arminjon
** Last update Thu Mar  9 10:21:18 2017 Enguerrand Arminjon
*/

#include "tetris.h"

int	check_left_move(char **tetri_map, int s)
{
  int	i;
  int	j;

  j = 1;
  i = 1;
  while (tetri_map[i][j + 1] != '\0')
    {
      i = 1;
      while (i < s)
	{
	  if (tetri_map[i][j] == ' ' || (tetri_map[i][j] >= '0'
					 && tetri_map[i][j] <= '9'))
	    {
	      if ((j - 1 == 0) ||
		  (j - 1 > 0  && tetri_map[i][j - 1] != '.' &&
		   tetri_map[i][j - 1] != ' ' &&
		   (tetri_map[i][j - 1] < '0' || tetri_map[i][j - 1] > '9')))
		return (1);
	    }
	  i++;
	}
      j++;
    }
  return (0);
}

char	**move_my_shape_left(char **tetri_map, t_tetris *tetris, t_fall *fall)
{
  int	size;
  int	nb;
  int	i;
  int	j;

  j = 0;
  size = tetris->t_debug->row + 1;
  if ((nb = check_left_move(tetri_map, size)) == 0)
    while (tetri_map[0][++j + 1] != '\0')
      {
	i = 0;
	while (++i <= size)
	  {
	    if (tetri_map[i][j] == ' '
		|| (tetri_map[i][j] >= '0' && tetri_map[i][j] <= '9'))
	      {
		if (tetri_map[i][j] != ' ')
		  tetri_map[i][j - 1] = fall->color + 48;
		else
		  tetri_map[i][j - 1] = ' ';
		tetri_map[i][j] = '.';
	      }
	  }
      }
  return (tetri_map);
}

int	check_right_move(char **tetr_map, t_tetris *tetris, int size)
{
  int	i;
  int	j;
  int	size_col;

  i = 1;
  size_col = tetris->t_debug->col;
  j = size_col + 1;
  while (--j > 0)
    {
      i = 1;
      while (i < size)
	{
	  if (tetr_map[i][j] == ' '
	      || (tetr_map[i][j] >= '0' && tetr_map[i][j] <= '9'))
	    {
	      if ((j == size_col) ||
		  (j + 1 <= size_col && tetr_map[i][j + 1] != '.' &&
		   tetr_map[i][j + 1] != ' ' &&
		   (tetr_map[i][j + 1] < '0' || tetr_map[i][j + 1] > '9')))
		return (1);
	    }
	  i++;
	}
    }
  return (0);
}

char	**move_my_shape_right(char **tetri_map, t_tetris *tetris, t_fall *fall)
{
  int	size;
  int	nb;
  int	i;
  int	j;

  j = tetris->t_debug->col;
  size = tetris->t_debug->row;
  if ((nb = check_right_move(tetri_map, tetris, size)) == 0)
    while (--j > 0)
      {
	i = 0;
	while (++i <= size)
	  {
	    if (tetri_map[i][j] == ' '
		|| (tetri_map[i][j] >= '0' && tetri_map[i][j] <= '9'))
	      {
		if (tetri_map[i][j] != ' ')
		  tetri_map[i][j + 1] = fall->color + 48;
		else
		  tetri_map[i][j + 1] = ' ';
		tetri_map[i][j] = '.';
	      }
	  }
      }
  return (tetri_map);
}
