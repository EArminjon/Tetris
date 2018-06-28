/*
** my_str_isnum.c for  in /home/armin.pc/delivery/CPool_Day07/lib/my
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Oct 12 08:51:31 2016 Enguerrand Arminjon
** Last update Tue Oct 25 17:44:07 2016 Enguerrand Arminjon
*/

#include <stdlib.h>

int	my_str_isnum(char *str)
{
  int	a;

  a = 0;
  if (str == NULL)
    return (1);
  while (str[a] != '\0' && str[a] >= '0' && str[a] <= '9')
    {
      a = a + 1;
      if (str[a] == '\0')
	return (0);
    }
  return (1);
}
