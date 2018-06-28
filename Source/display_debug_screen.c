/*
** display_debug_screen.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Mar 16 13:56:00 2017 Enguerrand Arminjon
** Last update Thu Mar 16 13:56:37 2017 Enguerrand Arminjon
*/

#include "tetris.h"
#include "my.h"

void	display_debug_screen(t_debug *t_d)
{
  my_putstr("*** DEBUG MODE ***\nKey Left : ");
  display_sequence(t_d->left);
  my_putstr("Key Right : ");
  display_sequence(t_d->right);
  my_putstr("Key Turn : ");
  display_sequence(t_d->top);
  my_putstr("Key Drop : ");
  display_sequence(t_d->drop);
  my_putstr("Key Quit : ");
  display_sequence(t_d->quit);
  my_putstr("Key Pause : ");
  display_sequence(t_d->pause);
  my_printf("Next : %s\nLevel : ", t_d->w_next);
  my_printf("%s\nSize : %i*%i\n", t_d->num, t_d->row, t_d->col);
}
