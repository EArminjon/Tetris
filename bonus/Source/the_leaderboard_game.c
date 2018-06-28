/*
** the_leaderboard_game.c for  in /home/armin.pc/delivery/PSU_2016_tetris/bonus
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Mar 14 13:41:43 2017 Enguerrand Arminjon
** Last update Tue Mar 14 13:43:04 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

int	the_leaderboard_game()
{
  int	row;
  int	col;
  char	*s;
  int	fd;

  if ((fd = open("Leaderboard/leaderboard", O_CREAT | O_RDONLY, 0777)) == -1)
    return (84);
  getmaxyx(stdscr, row, col);
  clear();
  s = get_next_line(fd);
  mvprintw((row / 2 - 5 + 1), ((col / 2) - 6), "NAME : %s", s);
  free(s);
  s = get_next_line(fd);
  mvprintw((row / 2 - 5 + 2), ((col / 2) - 6), "Score : %s", s);
  free(s);
  while ((s = get_next_line(fd)) != NULL)
    free(s);
  refresh();
  nodelay(stdscr, FALSE);
  getch();
  nodelay(stdscr, TRUE);
  clear();
  close(fd);
  return (0);
}
