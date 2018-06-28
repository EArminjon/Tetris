/*
** structure_debug.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Feb 21 12:07:39 2017 Enguerrand Arminjon
** Last update Sat Mar 18 15:38:37 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "my_error.h"

#define MINI(A, B) ((A) <= (B) ? (A) : (B))

int		k_key_next(char **av, int *i, t_tetris *tetris)
{
  static int	a = 0;
  static int	b = 0;

  if (my_strcmp(av[*i], "-kq") == 0 && av[*i + 1] != NULL && a == 0)
    tetris->quit = av[++*i + a++];
  else if (my_strcmp_2(av[*i], "--key-quit", '=') == 0 && a == 0)
    tetris->quit = find_cmds(av[*i + a++], '=');
  else if (my_strcmp(av[*i], "-kp") == 0 && av[*i + 1] != NULL && b == 0)
    tetris->pause = av[++*i + b++];
  else if (my_strcmp_2(av[*i], "--key-pause", '=') == 0 && b == 0)
    tetris->pause = find_cmds(av[*i + b++], '=');
  else
    return (COMMAND_NOT_FOUND);
  return (0);
}

int		k_key(char **av, int *i, t_tetris *tetris)
{
  static int	a = 0;
  static int	b = 0;
  static int	c = 0;
  static int	d = 0;

  if (my_strcmp(av[*i], "-kl") == 0 && av[*i + 1] != NULL && a == 0)
    tetris->left = av[++*i + a++];
  else if (my_strcmp_2(av[*i], "--key-left", '=') == 0 && a == 0)
    tetris->left = find_cmds(av[*i + a++], '=');
  else if (my_strcmp(av[*i], "-kr") == 0 && av[*i + 1] != NULL && b == 0)
    tetris->right = av[++*i + b++];
  else if (my_strcmp_2(av[*i], "--key-right", '=') == 0 && b == 0)
    tetris->right = find_cmds(av[*i+ b++], '=');
  else if (my_strcmp(av[*i], "-kt") == 0 && av[*i + 1] != NULL && c == 0)
    tetris->top = av[++*i + c++];
  else if (my_strcmp_2(av[*i], "--key-top", '=') == 0 && c == 0)
    tetris->top = find_cmds(av[*i + c++], '=');
  else if (my_strcmp(av[*i], "-kd") == 0 && av[*i + 1] != NULL && d == 0)
    tetris->drop = av[++*i + d++];
  else if (my_strcmp_2(av[*i], "--key-down", '=') == 0 && d == 0)
    tetris->drop = find_cmds(av[*i + d++], '=');
  else
    if ((k_key_next(av, i, tetris)) == COMMAND_NOT_FOUND)
      return (COMMAND_NOT_FOUND);
  return (0);
}

char		**malloc_my_struct_tab(char **tab)
{
  int		i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * 7)) == NULL)
    return (NULL);
  while (i < 6)
    {
      if ((tab[i] = malloc(sizeof(char) * 200)) == NULL)
	return (NULL);
      tab[i][0] = '\0';
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

int	confront_all_key_with_a_tab(char **tab)
{
  int	guest;
  int	min_len;
  int	current;

  current = 0;
  while (tab[current + 1] != NULL)
    {
      guest = current + 1;
      while (tab[guest] != NULL)
	{
	  min_len = MINI(my_strlen(tab[current]), my_strlen(tab[guest]));
	  if ((my_strncmp(tab[current], tab[guest], min_len)) == 0)
	    return (84);
	  ++guest;
	}
      ++current;
    }
  return (0);
}

int		confront_all_key(t_tetris *tetris)
{
  char		**tab;
  int		nb;

  nb = 0;
  tab = NULL;
  if (my_getnbr(tetris->num) < 1 || tetris->row <= 0 || tetris->col <= 0)
    return (ERROR);
  tab = malloc_my_struct_tab(tab);
  tab[0] = tetris->left;
  tab[1] = tetris->right;
  tab[2] = tetris->top;
  tab[3] = tetris->drop;
  tab[4] = tetris->quit;
  tab[5] = tetris->pause;
  tab[6] = '\0';
  nb = confront_all_key_with_a_tab(tab);
  return (nb);
}
