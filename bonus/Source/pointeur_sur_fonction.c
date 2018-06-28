/*
** pointeur_sur_fonction.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Feb 21 19:06:16 2017 Enguerrand Arminjon
** Last update Wed Mar  8 10:35:02 2017 Enguerrand Arminjon
*/

#include "my.h"
#include "tetris.h"
#include "my_error.h"

int	(*fct_point_2[6])(char **av, int *i, t_tetris *tetris) =
{
  l_num,
  k_key,
  map_size,
  w_without,
  d_debug,
  my_tetris_help,
};

int	init_struct_prompt__(char **av, int *i, t_tetris *tetris)
{
  char	str[6] = "lkmwdh";
  int	j;

  j = 0;
  if (av[*i][1] == '-')
    {
      while (str[j] != av[*i][2] && j < 6)
	j++;
      if (j < 6)
	{
	  if ((fct_point_2[j](av, i, tetris)) == 84)
	    return (COMMAND_NOT_FOUND);
	}
      else
	return (COMMAND_NOT_FOUND);
    }
  else
    return (COMMAND_NOT_FOUND);
  return (SUCCESS);
}

int	(*fct_point[6])(char **av, int *i, t_tetris *tetris) =
{
  l_num,
  k_key,
  map_size,
  w_without,
  d_debug,
  init_struct_prompt__,
};

int	init_struct_prompt(t_tetris *tetris, int ac, char **av)
{
  char	str[6] = "lkmwd-";
  int	i;
  int	j;

  i = 1;
  while (i < ac)
    {
      j = 0;
      if (av[i][0] == '-')
	{
	  while (str[j] != av[i][1] && j < 6)
	    j++;
	  if (j < 6)
	    {
	      if ((fct_point[j](av, &i, tetris)) == 84)
		return (COMMAND_NOT_FOUND);
	    }
	  else
	    return (COMMAND_NOT_FOUND);
	}
      else
	return (COMMAND_NOT_FOUND);
      i++;
    }
  return (SUCCESS);
}
