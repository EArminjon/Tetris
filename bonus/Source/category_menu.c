/*
** category_menu.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Mar  7 16:16:09 2017 Enguerrand Arminjon
** Last update Sat Mar 18 16:54:34 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"

void	print_option_menu(int row, int col, int l)
{
  print_tetris_title();
  if (l == row - 1)
    attron(COLOR_PAIR(10));
  mvprintw(row - 1, col - 6, "%s", "      LEVEL      ");
  attron(COLOR_PAIR(11));
  if (l == row)
    attron(COLOR_PAIR(10));
  mvprintw(row + 0, col - 6, "%s", "      NAME       ");
  attron(COLOR_PAIR(11));
  if (l == row + 1)
    attron(COLOR_PAIR(10));
  mvprintw(row + 1, col - 6, "%s", "RESET LEADERBOARD");
  attron(COLOR_PAIR(11));
  if (l == row + 2)
    attron(COLOR_PAIR(10));
  mvprintw(row + 2, col - 6, "%s", "     RETURN      ");
  attron(COLOR_PAIR(11));
}

int	option_key_bold(int c, int l, int row, t_tetris *tetris)
{
  if (c == KEY_DOWN && l < row + 2)
    l++;
  else if (c == KEY_UP && l > row - 1)
    l--;
  else if (c == '\n')
    {
      if ((do_option(l, tetris, row, COLS / 2)) == 84)
	return (-84);
    }
  else if (l < row - 1 || l > row + 2)
    l = row - 1;
  return (l);
}

int	option_check_size_term(int row, int col, int l)
{
  while (row - 2 <= 0 || row < 10 || col < 10 || col - 2 <= 0)
    {
      clear();
      mvprintw(row / 2, (col - 13)/2, "%s", "Enlarge map !");
      getmaxyx(stdscr, row, col);
      refresh();
      l = ((row / 2) - 1);
    }
  return (l);
}

int	the_game_option(t_tetris *tetris)
{
  int	row;
  int	col;
  int	l;
  int	c;

  clear();
  tetris->end = 43;
  getmaxyx(stdscr, row, col);
  l = ((row / 2) - 1);
  while (tetris->end == 43)
    {
      c = 0;
      getmaxyx(stdscr, row, col);
      l = option_check_size_term(row, col, l);
      c = getch();
      clear();
      if ((l = option_key_bold(c, l, row / 2, tetris)) == 84)
	return (84);
      print_option_menu(row / 2, col / 2, l);
      refresh();
    }
  tetris->end = 42;
  return (0);
}

int	do_action(int l, int i, t_tetris *tetris)
{
  int	nb;

  nb = 0;
  if (l == i - 1)
    tetris->end = 0;
  else if (l == i)
    nb = the_game_option(tetris);
  else if (l == i + 1)
    nb = the_leaderboard_game();
  else if (l == i + 2)
    tetris->end = 1;
  return (nb);
}
