/*
** check_my_envp.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Mar  6 10:00:46 2017 Enguerrand Arminjon
** Last update Thu Mar  9 10:55:56 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

char	*find_the_term(char *string)
{
  char	*str;
  int	i;

  i = 0;
  while (string[i] != '=')
    i++;
  i++;
  if ((str = malloc(sizeof(char) * (my_strlen(string) - i + 1))) == NULL)
    return (NULL);
  str[0] = '\0';
  str = my_strcat(str, &string[i]);
  return (str);
}

int	check_my_envp(t_tetris *tetris, char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strcmp_2(envp[i], "TERM", '=') == 0)
	{
	  if ((tetris->term = find_the_term(envp[i])) == NULL)
	    return (84);
	  return (0);
	}
      i++;
    }
  return (84);
}
