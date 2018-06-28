/*
** second_fonction_for_structure_debug.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Feb 21 12:10:00 2017 Enguerrand Arminjon
** Last update Sat Mar 18 11:18:33 2017 Enguerrand Arminjon
*/

#include <term.h>
#include <ncurses.h>
#include "tetris.h"

char	*find_cmds(char *str, char sep)
{
  if (*str != sep && *str != '\0')
    {
      while (*str != sep && *str != '\0')
	str++;
      str++;
    }
  return (str);
}

int	init_struct(t_debug *t_debug, char *term)
{
  int	err;

  if ((setupterm(term, 1, &err)) == -1)
    return (84);
  t_debug->num = "1";
  if (((t_debug->left = tigetstr("kcub1")) == NULL)
      || ((t_debug->right = tigetstr("kcuf1")) == NULL)
      || ((t_debug->top = tigetstr("kcuu1")) == NULL)
      || ((t_debug->drop = tigetstr("kcud1")) == NULL))
    return (84);
  t_debug->quit = "q";
  t_debug->pause = " ";
  t_debug->row = 20;
  t_debug->col = 10;
  t_debug->w_next = "Yes";
  t_debug->debug = "false";
  return (0);
}
