/*
** my_put_in_tab.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Feb 21 13:20:05 2017 Enguerrand Arminjon
** Last update Wed Mar 15 12:52:04 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char		*find_nb_in_str(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != '=')
    i++;
  i++;
  return (&str[i]);
}

char		*find_x_nb_in_str(char *str, int nb)
{
  static int	j = 0;
  static int	i = 0;

  if (nb == 1)
    {
      j = 0;
      i = 0;
      return (NULL);
    }
  i = j;
  while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
    i++;
  j = i;
  while (str[j] != '\0' && (str[j] >= '0' && str[j] <= '9'))
    j++;
  return (&str[i]);
}

char		**my_malloc_tab(t_d_shape *sha, char *s, int fd)
{
  int		i;

  i = 0;
  if ((sha->my_tab = malloc(sizeof(char *) * (sha->high + 3))) == NULL)
    return (NULL);
  while (i < sha->high + 2)
    {
      if ((sha->my_tab[i] = malloc(sizeof(char) * (sha->weight + 2))) == NULL)
	return (NULL);
      sha->my_tab[i][0] = '\0';
      i++;
    }
  sha->my_tab[i] = NULL;
  i = 0;
  while ((s = get_next_line(fd)) != NULL)
    {
      sha->my_tab[i] = my_strcat(sha->my_tab[i], s);
      free(s);
      i++;
    }
  sha->my_tab[i] = NULL;
  return (sha->my_tab);
}

char		**my_put_in_tab(t_d_shape *d_shape, int fd)
{
  char		*s;

  if (fd == -1)
    return (NULL);
  if ((s = get_next_line(fd)) == NULL)
    return (NULL);
  find_x_nb_in_str(NULL, 1);
  d_shape->my_tab = NULL;
  d_shape->weight = my_getnbr(find_x_nb_in_str(s, 0));
  d_shape->high = my_getnbr(find_x_nb_in_str(s, 0));
  d_shape->color = my_getnbr(find_x_nb_in_str(s, 0));
  if ((d_shape->my_tab = my_malloc_tab(d_shape, s, fd)) == NULL)
    return (NULL);
  return (d_shape->my_tab);
}
