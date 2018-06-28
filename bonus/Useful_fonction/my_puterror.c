/*
** my_putstr.c for  in /home/armin.pc/delivery/CPool_Day04
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Oct  6 18:08:09 2016 Enguerrand Arminjon
** Last update Tue Jan 31 10:46:20 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include "my.h"

int	my_puterror(char *str, int nb, int ret)
{
  if (str == NULL)
    return (0);
  write(nb, str, my_strlen(str));
  return (ret);
}
