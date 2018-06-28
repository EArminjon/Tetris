/*
** malloc_tab.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Feb 24 09:15:38 2017 Enguerrand Arminjon
** Last update Tue Feb 28 18:01:56 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

char	**malloc_tab(char **tab, int row, int col)
{
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (row + 1))) == NULL)
    return (NULL);
  while (i < row)
    {
      if ((tab[i] = malloc(sizeof(char) * (col + 1))) == NULL)
	return (NULL);
      tab[i][0] = '\0';
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
