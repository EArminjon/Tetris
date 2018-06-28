/*
** random.c for  in /home/armin.pc/delivery/CPE_2016_matchstick_bootstrap
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Feb 13 15:51:09 2017 Enguerrand Arminjon
** Last update Mon Feb 27 16:26:54 2017 Enguerrand Arminjon
*/

#include <time.h>
#include <stdlib.h>

int		my_random(int min, int max)
{
  static int	i;

  if (i == 0)
    {
      srand(time(NULL));
      i = 1;
    }
  return (rand() % (max - min + 1) + min);
}
