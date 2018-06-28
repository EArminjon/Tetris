/*
** fonction_for_structure_debug.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Feb 21 12:08:46 2017 Enguerrand Arminjon
** Last update Mon Mar 13 09:10:27 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

int		l_num(char **av, int *i, t_tetris *tetris)
{
  static int	a = 0;

  if ((my_strcmp(av[*i], "-l") == 0) && av[*i + 1] != '\0'
      && (my_str_isnum(av[*i + 1]) == 0) && a == 0)
    {
      tetris->num = av[*i + 1];
      if ((my_getnbr(tetris->num) < 0))
	return (84);
      *i = *i + 1;
      a = 1;
    }
  else if ((my_strcmp_2(av[*i], "--level", '=')) == 0 && a == 0)
    {
      tetris->num = find_cmds(av[*i], '=');
      a = 1;
    }
  else
    return (84);
  return (0);
}

int		d_debug(char **av, int *i, t_tetris *tetris)
{
  if (my_strcmp(av[*i], "-d") == 0 || my_strcmp(av[*i], "--debug") == 0)
    tetris->debug = "Yes";
  else
    return (84);
  return (0);
}

char		*find_nb(char *str, char sep)
{
  int		i;
  int		j;

  i = 0;
  while (*str != sep && *str != '\0')
    {
      i++;
      str++;
    }
  str++;
  j = i;
  while (str[j] != sep && str[j] != '\0')
    j++;
  str[j] = '\0';
  return (str);
}

int		map_size(char **av, int *i, t_tetris *tetris)
{
  static int	a = 0;

  if (((my_strcmp_2(av[*i], "--map-size", '=')) == 0) && a == 0)
    {
      tetris->row = my_getnbr(find_nb(av[*i], '='));
      tetris->col = my_getnbr(find_nb(av[*i], ','));
      a = 1;
    }
  else
    return (84);
  return (0);
}

int		w_without(char **av, int *i, t_tetris *tetris)
{
  if (my_strcmp(av[*i], "-w") == 0 || my_strcmp(av[*i], "--without-next") == 0)
    tetris->w_next = "No";
  else
    return (84);
  return (0);
}
