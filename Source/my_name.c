/*
** my_name.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Mar  9 13:16:15 2017 Enguerrand Arminjon
** Last update Thu Mar  9 13:16:40 2017 Enguerrand Arminjon
*/

#include "my.h"

char	*my_name(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(str);
  while (str[i] != '/' && i > 0)
    i--;
  if (str[i] == '/')
    i++;
  while (j < i)
    {
      str++;
      j++;
    }
  j++;
  return (my_strcut(str, '.'));
}
