/*
** chained_list.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Mar  9 13:10:30 2017 Enguerrand Arminjon
** Last update Thu Mar  9 13:12:13 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "my_error.h"

int	chained_list(t_shape *shape, t_shape *new, char **tab, t_tetris *tetris)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tab[i] != NULL)
    {
      new->map = NULL;
      my_check_tetrimino(tab[i++], tetris->d, new, tetris);
      if (new->map != NULL)
	{
	  while (shape->next != NULL)
	    shape = shape->next;
	  shape->map = new->map;
	  shape->high = new->high;
	  shape->weight = new->weight;
	  shape->color = new->color;
	  shape->next = new;
	  j++;
	}
      if ((new = malloc(sizeof(*new))) == NULL)
	return (MALLOC_CHAINED_LIST_FAIL);
      new->next = NULL;
    }
  return (j);
}

int	display_list_tetri(t_shape *shape, t_tetris *tetris)
{
  if (shape == NULL || shape->map == NULL)
    return (84);
  while (shape->next != NULL)
    {
      if (shape->high > tetris->max_high)
	tetris->max_high = shape->high;
      if (shape->weight > tetris->max_weight)
	tetris->max_weight = shape->weight;
      shape = shape->next;
    }
  return (0);
}

void	free_list_tetri(t_shape *shape)
{
  while (shape->next != NULL)
    {
      free_tab(shape->map);
      shape = shape->next;
    }
  free(shape);
}
