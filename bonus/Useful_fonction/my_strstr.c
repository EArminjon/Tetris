/*
** my_strstr.c for  in /home/armin.pc/delivery/CPool_Day06
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Oct 10 17:09:59 2016 Enguerrand Arminjon
** Last update Tue Mar 14 11:33:40 2017 Enguerrand Arminjon
*/

#include "my.h"

int	my_strstr(char *str, char *to_find)
{
  int	a;
  int	b;

  a = 0;
  while (str[a] != '\0')
    {
      b = 0;
      if (str[a] == to_find[b])
	{
	  while (str[a] == to_find[b] && to_find[b] != '\0' && str[a] != '\0')
	    {
	      a++;
	      b++;
	    }
	  if (to_find[b] == '\0')
	    return (0);
	}
      a++;
    }
  return (1);
}
