/*
** choose_option.c for  in /home/armin.pc/delivery/PSU_2016_tetris/bonus
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Mar 14 13:37:15 2017 Enguerrand Arminjon
** Last update Sat Mar 18 15:46:10 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"

void	choose_level(int row, int col, t_tetris *tetris)
{
  char	*s;
  int	x;

  x = 1;
  clear();
  mvprintw(row - 1, col - 6, "%s", "     ENTER A LEVEL     ");
  mvprintw(row + 1, col - 6, "%s ", "   THEN, PRESS SPACE   ");
  refresh();
  s = press_any_key(1, 1, 0, 0);
  while (x == 1)
    {
      s = press_any_key(0, 1, 0, 0);
      if (s != NULL)
	{
	  mvprintw(row + 3, col, "%s ", s);
	  x = my_strstr(s, " ");
	}
      refresh();
    }
  tetris->level = my_getnbr(s);
  s = press_any_key(1, 1, 0, 0);
  refresh();
}

int	change_name(char *str, t_tetris *tetris)
{
  free(tetris->name);
  if ((tetris->name = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (84);
  tetris->name[0] = '\0';
  tetris->name = my_strcat(tetris->name, str);
  return (0);
}

int	choose_name(int row, int col, t_tetris *tetris)
{
  char	*s;
  int	x;

  x = 1;
  clear();
  mvprintw(row - 1, col - 6, "%s", "    ENTER YOUR NAME    ");
  mvprintw(row + 1, col - 6, "%s ", "   THEN, PRESS SPACE   ");
  refresh();
  s = press_any_key(1, 1, 0, 0);
  while (x == 1)
    {
      s = press_any_key(0, 1, 0, 0);
      if (s != NULL)
	{
	  mvprintw(row + 3, col, "%s ", s);
	  x = my_strstr(s, " ");
	}
      refresh();
    }
  if (s != NULL && s[0] != '\0' && s[0] != '\n')
    if ((change_name(s, tetris)) == 84)
      return (84);
  s = press_any_key(1, 1, 0, 0);
  refresh();
  return (0);
}

int	reset_leader(int row, int col, t_tetris *tetris)
{
  char	*s;
  int	fd;
  int	x;

  x = 1;
  if ((fd = open("Leaderboard/leaderboard", O_CREAT | O_RDONLY | O_TRUNC,
		 0777)) == -1)
    return (84);
  tetris->high_score = 0;
  write(fd, "Jean\n0\0", 7);
  clear();
  close(fd);
  mvprintw(row - 1, col - 6, "%s", "    LEARDERBOARD CLEAR    ");
  mvprintw(row + 1, col - 6, "%s ", "    THEN, PRESS SPACE     ");
  refresh();
  s = press_any_key(1, 1, 0, 0);
  while (x == 1)
    {
      s = press_any_key(0, 1, 0, 0);
      if (s != NULL)
	x = my_strstr(s, " ");
    }
  s = press_any_key(1, 1, 0, 0);
  return (0);
}

int	do_option(int l, t_tetris *tetris, int row, int col)
{
  int	nb;

  nb = 0;
  if (l == row - 1)
    choose_level(row, col, tetris);
  else if (l == row)
    nb = choose_name(row, col, tetris);
  else if (l == row + 1)
    nb = reset_leader(row, col, tetris);
  else if (l == row + 2)
    tetris->end = 1;
  return (nb);
}
