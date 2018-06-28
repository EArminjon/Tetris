/*
** display_menu.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Mar  7 10:37:24 2017 Enguerrand Arminjon
** Last update Sat Mar 18 16:54:49 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <ncurses.h>
#include <SFML/Audio.h>
#include "my.h"

int	print_menu(int i, int j, int l)
{
  print_tetris_title();
  if (l == i - 1)
    attron(COLOR_PAIR(10));
  mvprintw(i - 1, j - 6, "%s", "   PLAY    ");
  attron(COLOR_PAIR(11));
  if (l == i)
    attron(COLOR_PAIR(10));
  mvprintw(i + 0, j - 6, "%s", "  OPTION   ");
  attron(COLOR_PAIR(11));
  if (l == i + 1)
    attron(COLOR_PAIR(10));
  mvprintw(i + 1, j - 6, "%s", "LEADERBOARD");
  attron(COLOR_PAIR(11));
  if (l == i + 2)
    attron(COLOR_PAIR(10));
  mvprintw(i + 2, j - 6, "%s", "   EXIT    ");
  attron(COLOR_PAIR(11));
  return (0);
}

int	key_bold(int c, int l, int i, t_tetris *tetris)
{
  if (c == KEY_DOWN && l < i + 2)
    l++;
  else if (c == KEY_UP && l > i - 1)
    l--;
  else if (c == '\n')
    {
      if ((do_action(l, i, tetris)) == 84)
	return (84);
    }
  else if (l < i - 1 || l > i + 2)
    l = i - 1;
  return (l);
}

int	check_size_term(int row, int col, int l)
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

int	my_extra_on_menu(t_tetris *tetris)
{
  if ((tetris->music = malloc(sizeof(char *) * 5)) == NULL)
    return (84);
  tetris->music[0] = sfMusic_createFromFile("./Music/remix.wav");
  tetris->music[1] = sfMusic_createFromFile("./Music/delete.wav");
  tetris->music[2] = sfMusic_createFromFile("./Music/win.wav");
  tetris->music[3] = sfMusic_createFromFile("./Music/lose.wav");
  tetris->music[4] = '\0';
  nodelay(stdscr, TRUE);
  start_color();
  init_pair(10, COLOR_BLACK, COLOR_WHITE);
  init_pair(11, COLOR_WHITE, COLOR_BLACK);
  sfMusic_play(tetris->music[0]);
  return (0);
}

int	display_menu(t_tetris *tetris)
{
  int	row;
  int	col;
  int	l;
  int	c;
  int	i;
  int	j;

  getmaxyx(stdscr, row, col);
  l = ((row / 2) - 1);
  my_extra_on_menu(tetris);
  while (tetris->end == 42)
    {
      c = 0;
      getmaxyx(stdscr, row, col);
      l = check_size_term(row, col, l);
      i = row / 2;
      j = col / 2;
      c = getch();
      clear();
      if ((l = key_bold(c, l, i, tetris)) == 84)
	return (84);
      print_menu(i, j, l);
      refresh();
    }
  return (tetris->end == 0 ? 0 : 1);
}
