/*
** second_fonction_for_structure_debug.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Feb 21 12:10:00 2017 Enguerrand Arminjon
** Last update Tue Mar 14 15:35:03 2017 Enguerrand Arminjon
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

int	init_struct(t_tetris *tetris)
{
  int	err;

  if ((setupterm(tetris->term, 1, &err)) == -1)
    return (84);
  tetris->num = "1";
  if (((tetris->left = tigetstr("kcub1")) == NULL)
      || ((tetris->right = tigetstr("kcuf1")) == NULL)
      || ((tetris->top = tigetstr("kcuu1")) == NULL)
      || ((tetris->drop = tigetstr("kcud1")) == NULL))
    return (84);
  tetris->quit = "q";
  tetris->pause = " ";
  tetris->row = 20;
  tetris->col = 10;
  tetris->w_next = "Yes";
  tetris->debug = "false";
  return (0);
}
