/*
** my_realloc.c for  in /home/armin.pc/delivery/CPE_2016_getnextline
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Sat Jan  7 09:53:20 2017 Enguerrand Arminjon
** Last update Sat Jan 21 11:53:44 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

char	*my_realloc(char *str, int size)
{
  char	*copy;
  int	i;

  if ((copy = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  i = 0;
  if (str == NULL)
    return (copy);
  while (str[i] != '\0')
    {
      copy[i] = str[i];
      i++;
    }
  copy[i] = '\0';
  free(str);
  return (copy);
}
