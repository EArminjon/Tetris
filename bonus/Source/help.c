/*
** help.c for  in /home/armin.pc/delivery/PSU_2016_tetris/bonus
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Mar  9 10:51:55 2017 Enguerrand Arminjon
** Last update Thu Mar  9 10:53:19 2017 Enguerrand Arminjon
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"
#include "my_error.h"

int	my_tetris_help(char **av, int *i, t_tetris *tetris)
{
  char	*s;
  int	fd;

  if ((my_strcmp(av[*i], "--help")) == 0)
    {
      if (tetris->help == 0)
	{
	  if ((fd = open("my_help", O_RDONLY)) == -1)
	    return (OPEN_FAIL);
	  tetris->help = 1;
	  my_printf("Usage: %s [option]\n", av[0]);
	  while ((s = get_next_line(fd)) != NULL)
	    {
	      my_printf("%s\n", s);
	      free(s);
	    }
	}
    }
  else
    return (COMMAND_NOT_FOUND);
  return (SUCCESS);
}
