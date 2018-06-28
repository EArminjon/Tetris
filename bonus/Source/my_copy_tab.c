/*
** my_copy_tab.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Feb 23 13:33:10 2017 Enguerrand Arminjon
** Last update Wed Mar 15 09:59:28 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int	count_row(char **tab)
{
  int	row;

  row = 0;
  while (tab[row] != NULL)
    row++;
  return (row);
}

int	count_col(char **tab)
{
  int	max;
  int	i;
  int	j;

  i = 0;
  max = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	j++;
      if (j > max)
	max = j;
      i++;
    }
  return (max);
}

char	**my_malloc_copy_tab(char **copy, char **tab)
{
  int	col;
  int	row;
  int	i;

  row = count_row(tab) + 1;
  col = count_col(tab) + 1;
  i = 0;
  if ((copy = malloc(sizeof(char *) * (row + 1))) == NULL)
    return (NULL);
  copy[0] = '\0';
  while (i < row)
    {
      if ((copy[i] = malloc(sizeof(char) * col)) == NULL)
	return (NULL);
      copy[i][0] = '\0';
      i++;
    }
  copy[i] = NULL;
  return (copy);
}

char	**my_copy_tab(char **copy, char **tab)
{
  int	i;

  if ((copy = my_malloc_copy_tab(copy, tab)) == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      copy[i] = my_strcat_custom(copy[i], tab[i], '*');
      i++;
    }
  copy[i] = NULL;
  copy = my_cut_tab(copy);
  return (copy);
}
