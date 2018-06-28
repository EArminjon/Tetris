/*
** display_game_over_file_leaderboard.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Mar  7 14:48:31 2017 Enguerrand Arminjon
** Last update Sun Mar 19 12:51:39 2017 Enguerrand Arminjon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"
#include "my.h"

int	write_on_the_leader(int score, int high, char *name)
{
  char	*s;
  int	fd;

  if (score >= high)
    {
      if ((fd = open("Leaderboard/leaderboard",
		     O_RDWR | O_TRUNC, 0777)) == -1)
	return (84);
      write(fd, name, my_strlen(name));
      write(fd, "\n", 1);
      if ((s = int_to_str(score)) == NULL)
	return (84);
      if (my_strlen(s) == 0)
	write(fd, "0", 1);
      else
	write(fd, s, my_strlen(s));
      free(s);
      close(fd);
    }
  return (0);
}

void	print_you_win(int score, int high, int r, int c)
{
  attron(COLOR_PAIR(8));
  attron(A_BOLD);
  mvprintw(r - 4, c, "%s", "         )    )                     (        )");
  mvprintw(r - 3, c, "%s", "   ( /( ( /(           (  (      )\\ )  ( /(");
  mvprintw(r - 2, c, "%s", "  )\\()))\\())     (    )\\))(   '(()/(  )\\\\()");
  mvprintw(r - 1, c, "%s", " ((_)\\((_)\\      )\\  ((_)()\\ )  /(_))((_)\\");
  mvprintw(r, c, "%s", "__ ((_) ((_)  _ ((_) _(())\\_)()(_))   _((_)");
  mvprintw(r + 1, c, "%s", "\\ \\ / // _ \\ | | | | \\ \\((_)/ /|_ _|| \\| |");
  mvprintw(r + 2, c, "%s", " \\ V /| (_) || |_| |  \\ \\/\\/ /  | | | .` |");
  mvprintw(r + 3, c, "%s", "  |_|  \\___/  \\___/    \\_/\\_/  |___||_|\\_|");
  mvprintw(r + 5, c, "\tYOUR SCORE : %i\t\t   HIGH SCORE : %i", score, high);
}

void	print_you_lose(int score, int high, int r, int c)
{
  attron(COLOR_PAIR(9));
  attron(A_BOLD);
  mvprintw(r - 4, c, "%s",   "       )    )           (        )   (");
  mvprintw(r - 3, c, "%s", "  ( /( ( /(           )\\ )  ( /(   )\\ )");
  mvprintw(r - 2, c, "%s", "  )\\()))\\())     (   (()/(  )\\()) (()/( (");
  mvprintw(r - 1, c, "%s", " ((_)\\((_)\\      )\\   /(_))((_)\\   /(_)))\\");
  mvprintw(r, c, "%s", "__ ((_) ((_)  _ ((_) (_))    ((_) (_)) ((_)");
  mvprintw(r + 1, c, "%s", "\\ \\ / // _ \\ | | | | | |    / _ \\ / __|| __|");
  mvprintw(r + 2, c, "%s", " \\ V /| (_) || |_| | | |__ | (_) |\\__ \\| _|");
  mvprintw(r + 3, c, "%s", "  |_|  \\___/  \\___/  |____| \\___/ |___/|___|");
  mvprintw(r + 5, c, "\tYOUR SCORE : %i\t\t   HIGH SCORE : %i", score, high);
}

void	main_win_lose(t_tetris *tetris, int high_score)
{
  int	row;
  int	col;

  start_color();
  init_pair(8, COLOR_GREEN, COLOR_BLACK);
  init_pair(9, COLOR_RED, COLOR_BLACK);
  getmaxyx(stdscr, row, col);
  row = row / 2;
  col = col / 2 - 49 / 2;
  sfMusic_destroy(tetris->music[0]);
  if (tetris->score >= high_score)
    {
      sfMusic_play(tetris->music[2]);
      print_you_win(tetris->score, high_score, row, col);
    }
  else
    {
      sfMusic_play(tetris->music[3]);
      print_you_lose(tetris->score, high_score, row, col);
    }
  refresh();
  nodelay(stdscr, FALSE);
  getch();
}

int	display_game_over_file_leaderboard(t_tetris *t, int nb)
{
  clear();
  main_win_lose(t, t->high_score);
  if ((write_on_the_leader(t->score, t->high_score, t->name)) == 84)
    {
      sfMusic_destroy(t->music[1]);
      sfMusic_destroy(t->music[2]);
      sfMusic_destroy(t->music[3]);
      return (84);
    }
  sfMusic_destroy(t->music[1]);
  sfMusic_destroy(t->music[2]);
  sfMusic_destroy(t->music[3]);
  sleep(2);
  return (nb);
}
