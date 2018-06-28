/*
** my_printf2.c for  in /home/armin.pc/delivery/PSU_2016_my_printf
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Nov 16 08:46:07 2016 Enguerrand Arminjon
** Last update Thu Jan  5 10:27:46 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int		my_size(int nb)
{
  int		size;

  size = 0;
  while (nb > 0)
    {
      nb = nb / 10;
      size++;
    }
  return (size);
}

void		my_binari(int nb)
{
  char		*array;
  int		res;
  int		i;

  i = 0;
  res = 0;
  array = malloc(sizeof(char) * my_size(nb) + 2);
  while (nb != 0)
    {
      res = nb % 2;
      if (res <= 2)
	res = res + '0';
      array[i] = res;
      nb = nb / 2;
      i++;
    }
  my_putstr(my_revstr(array));
}

void		my_hexadecimal(long int nb)
{
  char		*array;
  int		res;
  int		i;

  i = 0;
  res = 0;
  array = malloc(sizeof(char) * my_size(nb) + 2);
  if (nb == 0)
    my_putchar('0');
  while (nb != 0)
    {
      res = nb % 16;
      if (res <= 9)
	res = res + '0';
      else
	res = res + 55;
      array[i] = res;
      nb = nb / 16;
      i++;
    }
  my_putstr(my_revstr(array));
}

void		my_hexadecimal_2(long int nb)
{
  char		*array;
  int		res;
  int		i;

  i = 0;
  res = 0;
  array = malloc(sizeof(char) * my_size(nb) + 2);
  if (nb == 0)
    my_putchar('0');
  while (nb != 0)
    {
      res = nb % 16;
      if (res <= 9)
	res = res + '0';
      else
	res = res + 87;
      array[i] = res;
      nb = nb / 16;
      i = i + 1;
    }
  my_putstr(my_revstr(array));
}

void		the_else_print(int *a)
{
  my_putchar('%');
  *a = *a - 1;
}
