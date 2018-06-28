/*
** display_debug_screen.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Mar 16 13:56:00 2017 Enguerrand Arminjon
** Last update Sat Mar 18 17:06:47 2017 Enguerrand Arminjon
*/

#include "tetris.h"
#include "my.h"

void	display_debug_screen(t_tetris *t)
{
  my_putstr("*** DEBUG MODE ***\nKey Left : ");
  display_sequence(t->left);
  my_putstr("Key Right : ");
  display_sequence(t->right);
  my_putstr("Key Turn : ");
  display_sequence(t->top);
  my_putstr("Key Drop : ");
  display_sequence(t->drop);
  my_putstr("Key Quit : ");
  display_sequence(t->quit);
  my_putstr("Key Pause : ");
  display_sequence(t->pause);
  my_printf("Next : %s\nLevel : ", t->w_next);
  my_printf("%s\nSize : %i*%i\n", t->num, t->row, t->col);
}
