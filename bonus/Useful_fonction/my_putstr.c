/*
** my_putstr.c for  in /home/armin.pc/delivery/CPool_Day04
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Oct  6 18:08:09 2016 Enguerrand Arminjon
** Last update Sun Jan 15 19:30:39 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL || str[0] == '\0')
    return (0);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int	my_putstr(char *str)
{
  if (str == NULL)
    return (0);
  write(1, str, my_strlen(str));
  return (0);
}
