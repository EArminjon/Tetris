/*
** my_rotate_shape.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Mar  1 09:21:40 2017 Enguerrand Arminjon
** Last update Thu Mar  9 10:25:59 2017 Enguerrand Arminjon
*/

#include "tetris.h"
#include "my.h"

char		**rotate_my_map(char **tetri_map, char **copy, t_rotate *r,
				int i)
{
  int		j;

  r->high = r->last_row - r->first_row;
  r->weight = r->last_col - r->first_col;
  r->b = r->first_col;
  while (--i >= r->last_row - r->high)
    {
      r->a = r->last_row - r->weight / 2 - 1;
      j = r->first_col - 1;
      while (++j <= r->first_col + r->weight + 2)
	{
	  if (tetri_map[i][j] ==  ' '
	      || (tetri_map[i][j] >= '0' && tetri_map[i][j] <= '9'))
	    {
	      if ((r->a - (r->last_col - r->first_col) / 2) > 0
		  && copy[r->a][r->b] == '.')
		copy[r->a][r->b] = tetri_map[i][j];
	      else
		return (tetri_map);
	    }
	  ++r->a;
	}
      ++r->b;
    }
  return (copy);
}

char		**my_rotate_shape(char **tetri_map, t_tetris *tetris,
				  t_fall *fall)
{
  t_rotate	rotate;
  char		**copy;

  if (fall->high == 1)
    return (tetri_map);
  copy = NULL;
  copy = my_copy_tab(copy, tetri_map);
  copy = convert_for_rotate(copy);
  rotate.first_row = find_first_row_shape(tetri_map);
  rotate.last_row = find_last_row_shape(tetri_map, tetris->t_debug->row);
  rotate.first_col = find_first_col_shape(tetri_map);
  rotate.last_col = find_last_col_shape(tetri_map, tetris);
  copy = rotate_my_map(tetri_map, copy, &rotate, rotate.last_row + 1);
  return (copy);
}
