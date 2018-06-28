/*
** enlarge_map.c for  in /home/armin.pc/delivery/PSU_2016_tetris/bonus
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Mar  9 10:42:31 2017 Enguerrand Arminjon
** Last update Thu Mar  9 10:46:17 2017 Enguerrand Arminjon
*/

#include <ncurses.h>
#include "tetris.h"

void	load_color()
{
  start_color();
  init_pair(49, COLOR_WHITE, COLOR_WHITE);
  init_pair(50, COLOR_RED, COLOR_RED);
  init_pair(51, COLOR_GREEN, COLOR_GREEN);
  init_pair(52, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(53, COLOR_BLUE, COLOR_BLUE);
  init_pair(54, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(55, COLOR_CYAN, COLOR_CYAN);
  init_pair(56, COLOR_WHITE, COLOR_BLACK);
  init_pair(57, COLOR_WHITE, COLOR_WHITE);
}

void	enlarge_map(int row, int col, t_tetris *t)
{
  while (row < t->row + 2 || col < t->col)
    {
      clear();
      mvprintw(row / 2, (col - 13)/2, "%s", "Enlarge map !");
      getmaxyx(stdscr, row, col);
      refresh();
    }
}
