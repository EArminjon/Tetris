/*
** my_putstr_int.c for  in /home/armin.pc/delivery/CPool_Day04
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Oct  6 18:08:09 2016 Enguerrand Arminjon
** Last update Thu Jan  5 10:28:19 2017 Enguerrand Arminjon
*/

#include "my.h"

int	my_putstr_int(int *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_put_nbr(str[i]);
      i++;
      if (str[i] != '\0')
	my_putchar(' ');
    }
  return (0);
}
