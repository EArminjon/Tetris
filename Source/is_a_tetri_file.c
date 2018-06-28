/*
** is_a_tetri_file.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Mar  9 09:22:01 2017 Enguerrand Arminjon
** Last update Sun Mar 19 09:53:39 2017 Enguerrand Arminjon
*/

#include "my.h"

int	is_a_tetri_file(char *str)
{
  int	j;

  j = my_strlen(str);
  while (str[j] != '.' && j > 0)
    --j;
  if (str[j] == '.')
    if ((my_strcmp(&str[j], ".tetrimino")) == 0)
      return (0);
  return (1);
}
