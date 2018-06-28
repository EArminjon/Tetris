/*
** print_tetris_title.c for  in /home/armin.pc/delivery/PSU_2016_tetris/bonus
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Sat Mar 18 16:53:47 2017 Enguerrand Arminjon
** Last update Sat Mar 18 16:54:13 2017 Enguerrand Arminjon
*/

#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

void		print_tetris2(int a, int b, int fd)
{
  char		*s;
  int		nb;

  nb = 0;
  load_color();
  while ((s = get_next_line(fd)) != NULL)
    {
      nb = my_random(49, 55);
      attron(COLOR_PAIR(nb));
      a = 0;
      while (s[a] != '\0')
	{
	  if (s[a] == 'O')
	    mvprintw(LINES / 2 - 20 + b, COLS / 2 - 40 + a, "%c", s[a]);
	  a++;
	}
      b++;
      free(s);
      attroff(COLOR_PAIR(nb));
    }
}

int		print_tetris_title()
{
  int		fd;

  attron(A_BOLD);
  if ((fd = open("Picture/tetris_title.txt", O_RDONLY)) == -1)
    return (84);
  print_tetris2(0, 0, fd);
  close(fd);
  attroff(A_BOLD);
  return (0);
}
