/*
** my_putchar.c for  in /home/armin.pc/delivery/CPool_Day07
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Oct 11 10:31:47 2016 Enguerrand Arminjon
** Last update Fri Oct 14 14:30:52 2016 Enguerrand Arminjon
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
