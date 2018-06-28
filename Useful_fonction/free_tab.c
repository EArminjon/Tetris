/*
** free_and_exit.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Jan 19 16:30:01 2017 Enguerrand Arminjon
** Last update Thu Jan 19 16:33:11 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

char	**free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != '\0')
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
  return (NULL);
}
