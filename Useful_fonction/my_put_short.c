/*
** my_put_short.c for  in /home/armin.pc/delivery/CPool_Day03
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Oct  5 22:22:36 2016 Enguerrand Arminjon
** Last update Thu Jan  5 10:28:14 2017 Enguerrand Arminjon
*/

#include "my.h"

int	my_put_short(short x)
{
  if (x < 0)
    {
      my_putchar('-');
      x = x * (-1);
    }
  if (x >= 0 && x <= 9)
    {
      my_putchar(x + 48);
    }
  if (x > 9)
    {
      my_put_short(x / 10);
      my_put_short(x % 10);
    }
  return (0);
}
