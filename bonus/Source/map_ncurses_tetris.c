/*
** map_ncurses_tetris.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sun Feb 26 10:16:52 2017 Enguerrand Arminjon
** Last update Tue Mar 14 11:58:52 2017 Enguerrand Arminjon
*/

#include <time.h>
#include <ncurses.h>
#include "my.h"
#include "tetris.h"
#include "global.h"

void	display_color_map(char **map, t_tetris *t, int i, int j)
{
  while (map[i][++j] != '\0')
    {
      if (map[i][j] == '_' || map[i][j] == '.')
	{
	  attron(COLOR_PAIR(56));
	  mvprintw(t->rn - 1, (t->cn - t->col) / 2 + j, "%c", ' ');
	}
      else if (map[i][j] >= '0' && map[i][j] <= '9')
	{
	  attron(COLOR_PAIR(map[i][j]));
	  mvprintw(t->rn - 1, (t->cn - t->col) / 2 + j, "%c", '*');
	}
      else if (map[i][j] >= 'A' && map[i][j] <= 'Z')
	{
	  attron(COLOR_PAIR(map[i][j] - 16));
	  mvprintw(t->rn - 1, (t->cn - t->col) / 2 + j, "%c", '*');
	}
      else if (map[i][j] == '=' || map[i][j] == '/'
	       || map[i][j] == '\\' || map[i][j] == '|')
	{
	  attron(COLOR_PAIR(57));
	  mvprintw(t->rn - 1, (t->cn - t->col) / 2 + j, "%c", map[i][j]);
	}
    }
}

void	display_time(int time, int row, int col)
{
  int	min;

  min = 0;
  while (time > 60)
    {
      time = time - 60;
      min++;
    }
  if (min < 10)
    {
      if (time < 10)
	mvwprintw(stdscr, row, col, "| Timer\t: 0%i:0%i\t\t|", min, time);
      else
	mvwprintw(stdscr, row, col, "| Timer\t: 0%i:%i\t\t|", min, time);
    }
  else
    {
      if (time < 10)
	mvwprintw(stdscr, row, col, "| Timer\t: %i:0%i\t\t|", min, time);
      else
	mvwprintw(stdscr, row, col, "| Timer\t: %i:%i\t\t|", min, time);
    }
}

void	print_game_info_tetris(t_tetris *t)
{
  int	i;

  i = t->max_high;
  mvwprintw(stdscr, i + 1, 1, "%s", "--------------------------------");
  mvwprintw(stdscr, i + 3, 1, "| Name\t\t: %s\t|", t->name);
  mvwprintw(stdscr, i + 4, 1, "| High Score\t: %i\t\t|", t->high_score);
  mvwprintw(stdscr, i + 5, 1, "| Score\t: %i\t\t|", t->score);
  mvwprintw(stdscr, i + 6, 1, "| Lines\t: %i\t\t|", t->line);
  mvwprintw(stdscr, i + 7, 1, "| Level\t: %i\t\t|", t->level + t->line / 10);
  mvwprintw(stdscr, i + 8, 1, "%s", "--------------------------------");
}

void	small_window_near(t_tetris *t)
{
  int		time;
  int		row;
  int		i;
  int		j;

  getmaxyx(stdscr, row, i);
  i = -1;
  row = row / 2;
  attron(COLOR_PAIR(56));
  while (t->fall_copy->shape[++i] != NULL)
    {
      j = 0;
      while (t->fall_copy->shape[i][j])
	{
	  if (t->fall_copy->shape[i][j] == '.')
	    mvwprintw(stdscr, 1 + i, 1 + j, "%c", ' ');
	  else
	    mvwprintw(stdscr, 1 + i, 1 + j, "%c", t->fall_copy->shape[i][j]);
	  j++;
	}
    }
  time = ((clock() / 1000) - t->time->start) / 1000 + 1;
  display_time(time, t->max_high + 2, 1);
  print_game_info_tetris(t);
}

void	display_game(char **tetri_map, t_tetris *t, int i, int nw)
{
  int	col;
  int	row;

  getmaxyx(stdscr, row, col);
  load_color();
  if (row < t->row + 2 || col < t->col)
    enlarge_map(row, col, t);
  row = (row / 2) - (t->row / 2);
  t->cn = col;
  clear();
  while (tetri_map != NULL && i < t->row + 2)
    {
      if (t->debug[0] != 'f')
	mvprintw(row - 1, (col - t->col) / 2, "%s", tetri_map[i]);
      else
	{
	  t->rn = row;
	  display_color_map(tetri_map, t, i, -1);
	}
      row++;
      i++;
    }
  if (nw == 1 && t->w_next[0] == 'Y')
    small_window_near(t);
  refresh();
}
