/*
** enlarge_map.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Mar  9 13:21:44 2017 Enguerrand Arminjon
** Last update Thu Mar  9 13:23:28 2017 Enguerrand Arminjon
*/

#include <ncurses.h>
#include "tetris.h"

void	enlarge_map(int row, int col, t_tetris *t)
{
  while (row < t->t_debug->row + 2 || col < t->t_debug->col)
    {
      clear();
      mvprintw(row / 2, (col - 13)/2, "%s", "Enlarge map !");
      getmaxyx(stdscr, row, col);
      refresh();
    }
}
