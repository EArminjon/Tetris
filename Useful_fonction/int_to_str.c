/*
** int_to_str.c for  in /home/armin.pc/delivery/PSU_2016_tetris/bonus
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Mar  8 13:05:17 2017 Enguerrand Arminjon
** Last update Thu Mar  9 09:03:48 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	*int_to_str(int nb)
{
  int	len;
  char	*str;
  int	tmp;

  tmp = nb;
  len = 0;
  while (tmp > 0)
    {
      tmp /= 10;
      len++;
    }
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  str[len] = '\0';
  while (len--)
    {
      str[len] = nb % 10  + '0';
      nb /= 10;
    }
  return (str);
}
