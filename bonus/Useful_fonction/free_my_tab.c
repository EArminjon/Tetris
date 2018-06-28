/*
** free_my_tab.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Fri Jan  6 18:17:05 2017 Enguerrand Arminjon
** Last update Mon Jan 16 10:36:11 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

char	**free_my_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (NULL);
  while (tab[i] != '\0')
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (tab);
}
