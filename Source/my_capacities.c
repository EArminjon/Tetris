/*
** my_capacities.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Mar  6 10:22:17 2017 Enguerrand Arminjon
** Last update Sat Mar 18 15:37:08 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <term.h>
#include "my.h"
#include "tetris.h"
#include "my_error.h"

void			display_sequence(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i]) == 27)
	my_putstr("^E");
      else if (str[i] == ' ')
	my_putstr("(space)");
      else if (str[i] == '\t')
	my_putstr("(tab)");
      else if (str[i] == '\n')
	my_putstr("(enter)");
      else if (str[i] == 27)
	my_putstr("(escape)");
      else
	my_putchar(str[i]);
      i++;
    }
  my_putchar('\n');
}

char			*clear_str(char *str, int *i)
{
  int			a;

  a = 0;
  while (a <= 200)
    {
      str[a] = '\0';
      a++;
    }
  *i = 0;
  return (str);
}

struct termios		flags_iotcl(struct termios *old_t,
				    struct termios *new_t)
{
  new_t = old_t;
  new_t->c_lflag &= ~ECHO;
  new_t->c_lflag &= ~ICANON;
  return (*new_t);
}

char			*press_any_key(int reset, int on, int off, int j)
{
  struct termios	old_t;
  struct termios	new_t;
  static char		c[200];
  static int		i = 0;

  if (i == 200 || reset == 1)
    return (clear_str(c, &i));
  if ((ioctl(0, TCGETS, &old_t)) == -1)
    return (IOCTL);
  new_t = flags_iotcl(&old_t, &new_t);
  if (((ioctl(0, TCSETS, &new_t)) == -1) || ((ioctl(0, FIONBIO, &on)) == -1))
    return (IOCTL);
  j = read(0, &c[i], 1);
  if ((ioctl(0, FIONBIO, &off)) == -1)
    return (IOCTL);
  if (j == -1)
    {
      if ((ioctl(0, TCSETS, &old_t)) == -1)
	return (IOCTL);
      return (NULL);
    }
  if ((ioctl(0, TCSETS, &old_t)) == -1)
    return (IOCTL);
  c[i = i + j] = '\0';
  return (c);
}
