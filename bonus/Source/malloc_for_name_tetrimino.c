/*
** malloc_for_name_tetrimino.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Feb 23 10:58:05 2017 Enguerrand Arminjon
** Last update Sun Mar 19 09:54:53 2017 Enguerrand Arminjon
*/

#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my_error.h"
#include "my.h"

#define SIZE_FILE 11

char		**order_my_tab(char **tab)
{
  int		i;
  int		j;
  char		*tmp;

  i = 0;
  j = 0;
  while (tab[i] != NULL)
    {
      if (tab[i + 1] != NULL && tab[i][j] > tab[i + 1][j])
	{
	  tmp = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = tmp;
	  i = 0;
	  j = 0;
	}
      else if (tab[i + 1] != NULL && tab[i][j] == tab[i + 1][j])
	j++;
      else
	{
	  i++;
	  j = 0;
	}
    }
  return (tab);
}

char		**malloc_name(char **tab, int row, int col)
{
  int		i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (row + 1))) == NULL)
    return (FAIL_WITH_ALLOC_MEM);
  while (i < row)
    {
      if ((tab[i] = malloc(sizeof(char) * (col + SIZE_FILE + 1))) == NULL)
	return (FAIL_WITH_ALLOC_MEM);
      tab[i][0] = '\0';
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

char		**malloc_for_name_tetrimino(char **tab)
{
  DIR		*rep;
  struct dirent	*entry;
  int		max;
  int		i;
  int		j;

  i = 0;
  max = 0;
  if ((rep = opendir("tetriminos")) == NULL)
    return (TETRIMINOS_REP_NOT_FOUND);
  while ((entry = readdir(rep)) != NULL)
    {
      j = 0;
      if (is_a_tetri_file(entry->d_name) == 0)
	{
	  j = my_strlen(entry->d_name);
	  if (j >= max)
	    max = j;
	  i++;
	}
    }
  closedir(rep);
  if ((tab = malloc_name(tab, i, max)) == NULL)
    return (FAIL_WITH_ALLOC_MEM);
  return (tab);
}
