/*
** load_shape.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Mar  1 10:40:58 2017 Enguerrand Arminjon
** Last update Sat Mar 18 15:53:41 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

char		**load_the_shape(t_fall *fall, t_shape *shape, int n,
				 t_tetris *tetris)
{
  int		i;

  i = 1;
  while (shape->next != NULL && i < n)
    {
      shape = shape->next;
      i++;
    }
  if (shape != NULL)
    {
      fall->color = 0;
      fall->shape = my_copy_tab(fall->shape, shape->map);
      fall->color = shape->color;
      fall->high = shape->high;
      fall->weight = shape->weight;
    }
  tetris->f_next = 1;
  return (fall->shape);
}

char		**load_shape(t_fall *fall, t_shape *shape, t_tetris *t)
{
  static int	i = 0;
  int		nb;

  if (t->fall_copy == NULL)
    if ((t->fall_copy = malloc(sizeof(*t->fall_copy))) == NULL)
      return (NULL);
  if (i == 0)
    {
      nb = my_random(1, t->nb_good_shape);
      fall->shape = load_the_shape(fall, shape, nb, t);
    }
  else if (i == 1)
    {
      fall->shape = my_copy_tab(fall->shape, t->fall_copy->shape);
      fall->color = t->fall_copy->color;
      fall->high = t->fall_copy->high;
      fall->weight = t->fall_copy->weight;
      free_tab(t->fall_copy->shape);
    }
  nb = my_random(1, t->nb_good_shape);
  t->fall_copy->shape = load_the_shape(t->fall_copy, shape, nb, t);
  i = 1;
  return (fall->shape);
}

char		**load_shape_on_top(t_fall *fall, char **map,
				    t_tetris *tetris, int j)
{
  int		i;
  int		a;
  int		b;
  int		center;

  i = -1;
  a = 1;
  center = ((tetris->col + 2) / 2) - (fall->weight - fall->weight % 2) / 2;
  while (fall->shape[++i] != NULL)
    {
      b = center;
      j = -1;
      while (fall->shape[i][++j] != '\0')
	{
	  if (map[a][b] != '.' && map[a][b] != ' ')
	    return (NULL);
	  if (fall->shape[i][j] == '*')
	    map[a][b] = fall->color + 48;
	  else
	    map[a][b] = fall->shape[i][j];
	  b++;
	}
      a++;
    }
  return (map);
}
