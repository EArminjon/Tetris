/*
** shape_tetrimino.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Feb 21 12:11:19 2017 Enguerrand Arminjon
** Last update Sun Mar 19 09:52:56 2017 Enguerrand Arminjon
*/

#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "my_error.h"

int		display_error(char *file, int fd)
{
  char		*s;

  my_printf("Tetriminos : Name %s : Error\n", my_name(file));
  while ((s = get_next_line(fd)) != NULL)
    free(s);
  if ((close(fd)) == -1)
    return (CLOSE_FAIL);
  return (THIS_IS_AN_INVALIDE_SHAPE);
}

int		check_tab(t_d_shape *shape, int x, int i, int j)
{
  int		max;

  max = 0;
  if (shape->weight <= 0 || shape->high <= 0
      || shape->color <= 0 || shape->my_tab == NULL)
    return (INVALIDE_SHAPE);
  while (++i < shape->high)
    {
      x = 0;
      if ((shape->my_tab[i]) == NULL || shape->my_tab[i][0] == '\0'
	  || ((i + 1 == shape->high) && shape->my_tab[i + 1] != NULL
	      && shape->my_tab[i + 1][0] != '\0'))
	return (INVALIDE_SHAPE);
      j = 0;
      while (shape->my_tab[i][j] != '\0')
	if (shape->my_tab[i][j++] == '*')
	  x++;
      if (j > max)
	max = j;
      if (x == 0 || x > shape->weight)
	return (INVALIDE_SHAPE);
    }
  if (max < shape->weight)
    return (INVALIDE_SHAPE);
  return (SUCCESS);
}

int		second_check_tab(int nb, t_d_shape *d_shape, t_tetris *tetris)
{
  if (d_shape->high > tetris->t_debug->row
      || d_shape->weight > tetris->t_debug->col)
    return (84);
  return (nb);
}

int		my_check_tetrimino(char *f, int debug, t_shape *shape,
				   t_tetris *tetris)
{
  t_d_shape	d_shape;
  int		fd;
  int		nb;

  nb = 84;
  fd = open(f, O_RDONLY);
  if ((d_shape.my_tab = my_put_in_tab(&d_shape, fd)) != NULL)
    nb = second_check_tab(check_tab(&d_shape, 0, -1, 0), &d_shape, tetris);
  if (nb == 0 && debug == 1)
    {
      my_printf("Tetriminos : Name %s : Size %i", my_name(f), d_shape.weight);
      my_printf("*%i : Color %i :\n", d_shape.high, d_shape.color);
      print_tab(d_shape.my_tab);
    }
  else if (nb != 0 && debug == 1)
    return (display_error(f, fd));
  if (nb == 0)
    {
      shape->map = my_copy_tab(shape->map, d_shape.my_tab);
      shape->high = d_shape.high;
      shape->weight = d_shape.weight;
      shape->color = d_shape.color;
    }
  close(fd);
  return (SUCCESS);
}

char		**display_tetriminos(t_debug *t_debug, int i, int deb)
{
  DIR		*rep;
  struct dirent	*entry;
  char		**my_tab;

  my_tab = NULL;
  if (((my_tab = malloc_for_name_tetrimino(my_tab)) == NULL)
      || ((rep = opendir("tetriminos")) == NULL))
    return (TETRIMINOS_REP_NOT_FOUND);
  while ((entry = readdir(rep)) != NULL)
    {
      if (is_a_tetri_file(entry->d_name) == 0)
	{
	  my_tab[i] = my_strcat(my_tab[i], "tetriminos/");
	  my_tab[i] = my_strcat(my_tab[i], entry->d_name);
	  i++;
	  t_debug->nb_tetri++;
	}
    }
  if (deb == 1)
    my_printf("Tetriminos : %i\n", t_debug->nb_tetri);
  if (i == 0)
    return (ANY_SHAPE_FOUND);
  closedir(rep);
  return (my_tab = order_my_tab(my_tab));
}
