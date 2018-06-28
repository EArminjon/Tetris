/*
** free_and_return_good_tab.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Fri Mar  3 15:15:49 2017 Enguerrand Arminjon
** Last update Fri Mar  3 15:32:25 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

char	**free_tab_return(char **free_tab, char **return_tab)
{
  int	i;

  i = 0;
  while (free_tab[i] != NULL)
    {
      free(free_tab[i]);
      i++;
    }
  if (free_tab != NULL)
    free(free_tab);
  return (return_tab);
}
