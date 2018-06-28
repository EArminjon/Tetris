/*
** main.c for  in /home/armin.pc/delivery/PSU_2016_tetris
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Feb 20 09:01:02 2017 Enguerrand Arminjon
** Last update Thu Mar 16 13:56:15 2017 Enguerrand Arminjon
*/

#include <termios.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"
#include "my_error.h"

int			display_debug(t_tetris *t, t_shape *shape,
				      t_debug *t_d)
{
  char			**tab;
  t_shape		*new;

  t->d = 0;
  tab = NULL;
  if ((new = malloc(sizeof(*new))) == NULL)
    return (MALLOC_FAIL);
  shape->map = NULL;
  shape->next = NULL;
  new->next = NULL;
  if (t_d->debug[0] == 'Y')
    {
      display_debug_screen(t_d);
      t->d = 1;
    }
  if ((tab = display_tetriminos(t->t_debug, 0, t->d)) == NULL)
    return (ERROR);
  t->nb_good_shape = chained_list(shape, new, tab, t);
  return (t->nb_good_shape == -84 ? 84 : 0);
}

int			press_any_key_to_play()
{
  struct termios	old_t;
  struct termios	new_t;
  char			c;

  my_putstr("Press any key to start Tetris\n");
  if ((ioctl(1, TCGETS, &old_t)) == -1)
    return (84);
  new_t = old_t;
  new_t.c_lflag &= ~ECHO;
  new_t.c_lflag &= ~ICANON;
  if (((ioctl(1, TCSETS, &new_t)) == -1)
      || ((read(1, &c, 1)) == -1)
      || ((ioctl(1, TCSETS, &old_t)) == -1))
    return (84);
  return (0);
}

int			main_tetris(t_tetris *tetris)
{
  t_shape		shape;
  int			nb;

  shape.color = -1;
  shape.high = -1;
  shape.weight = -1;
  if ((display_debug(tetris, &shape, tetris->t_debug)) == 84)
    return (84);
  if (tetris->t_debug->debug[0] == 'Y')
    if ((press_any_key_to_play()) == 84)
      return (84);
  if ((display_list_tetri(&shape, tetris)) == 84)
    return (84);
  nb = display_ncurses(&shape, tetris);
  free_list_tetri(&shape);
  return (nb == 84 ? 84 : 0);
}

int			add_in_struct(t_tetris *tetris, t_debug *t_debug)
{
  char			*str;
  int			fd;

  t_debug->nb_tetri = 0;
  t_debug->help = 0;
  tetris->max_high = 0;
  tetris->max_weight = 0;
  tetris->first = 0;
  tetris->end = 42;
  tetris->score = 0;
  tetris->fall_copy = NULL;
  if ((fd = open("Leaderboard/leaderboard", O_CREAT | O_RDONLY, 0777)) == -1)
    return (my_puterror("No leaderboard file ! \n", 2, 84));
  if ((str = get_next_line(fd)) != NULL)
    {
      tetris->high_score = my_getnbr(str);
      free(str);
      while ((str = get_next_line(fd)) != NULL)
	free(str);
    }
  else
    tetris->high_score = 0;
  if ((close(fd)) == -1)
    return (84);
  return (0);
}

int			main(int ac, char **av, char **envp)
{
  t_tetris		tetris;

  tetris.keys = 0;
  if ((tetris.t_debug = malloc(sizeof(*tetris.t_debug))) == NULL)
    return (my_puterror("ERROR\n", 2, 84));
  if (((add_in_struct(&tetris, tetris.t_debug)) == 84)
      || ((check_my_envp(&tetris, envp)) == 84)
      || ((init_struct(tetris.t_debug, tetris.term)) == 84))
    return (my_puterror("ERROR\n", 2, 84));
  if ((init_struct_prompt(&tetris, ac, av, "lkmwd-")) == 84)
    return (my_puterror("ERROR\n", 2, 84));
  if (tetris.t_debug->help == 1)
    return (0);
  if ((confront_all_key(tetris.t_debug)) == 84)
    return (my_puterror("ERROR\n", 2, 84));
  return (main_tetris(&tetris));
}
