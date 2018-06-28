/*
** my_str_isnum.c for  in /home/armin.pc/delivery/CPool_Day07/lib/my
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Oct 12 08:51:31 2016 Enguerrand Arminjon
** Last update Fri Oct 21 16:25:38 2016 Enguerrand Arminjon
*/

#include <stdlib.h>

int	my_str_islower(char *str)
{
  int	a;

  a = 0;
  if (str == NULL)
    return (1);
  while (str[a] != '\0' && str[a] >= 'a' && str[a] <= 'z')
    {
      a = a + 1;
      if (str[a] == '\0')
	return (1);
    }
  return (0);
}
