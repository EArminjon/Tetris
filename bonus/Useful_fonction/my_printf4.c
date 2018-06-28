/*
** my_printf4.c for  in /home/armin.pc/delivery/PSU_2016_my_printf
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Nov 17 17:09:26 2016 Enguerrand Arminjon
** Last update Thu Jan  5 10:57:21 2017 Enguerrand Arminjon
*/

#include <stdarg.h>
#include "my.h"

void		my_octal(long int nb)
{
  int		i;
  int		j;

  i = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  while ((nb / i) >= 8)
    i = i * 8;
  while (i > 0)
    {
      j = nb / i % 8;
      my_putchar(j + 48);
      i = i / 8;
    }
}

void		the_hashtag(char *s, va_list ap, int *a)
{
  va_list	new;

  *a = *a + 1;
  va_copy(new, ap);
  if (s[*a] == 'o' && va_arg(new, unsigned int) != 0)
    my_putchar('0');
  if (s[*a] == 'X' && va_arg(new, unsigned int) != 0)
    my_putstr("0X");
  if (s[*a] == 'x' && va_arg(new, unsigned int) != 0)
    my_putstr("0x");
}
