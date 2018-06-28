/*
** my_strcat.c for  in /home/armin.pc/delivery/PSU_2016_minishell1/srcs
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 10 09:27:04 2017 Enguerrand Arminjon
** Last update Wed Mar 15 09:49:17 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int	str_count_col(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	**my_cut_tab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == ' ')
	    tab[i][j] = '.';
	  j++;
	}
      i++;
    }
  return (tab);
}

char	*my_cut(char *str)
{
  int	i;

  i = 0;
  if (str[i] == ' ')
    while (str[i] == ' ')
      {
	str[i] = '.';
	i++;
      }
  return (str);
}

char	*my_strcat_custom(char *dest, char *src, char sep)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (dest[i] != '\0')
    i = i + 1;
  while (src[n] != '\0')
    {
      dest[i] = src[n];
      n = n + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  if (dest[i - 1] == ' ')
    while (dest[i - 1] != sep)
      i--;
  dest[i] = '\0';
  return (my_cut(dest));
}
