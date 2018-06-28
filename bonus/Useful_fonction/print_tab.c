/*
** print_tab.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 10 09:11:33 2017 Enguerrand Arminjon
** Last update Tue Jan 10 09:12:41 2017 Enguerrand Arminjon
*/

#include "my.h"

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
