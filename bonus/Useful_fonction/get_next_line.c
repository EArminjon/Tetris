/*
** get_next_line.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Jan 19 16:39:06 2017 Enguerrand Arminjon
** Last update Thu Mar  2 08:32:00 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char		get_next_char(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  static int	size = 0;
  static int	i = 0;
  char		my_char;

  if (size == 0)
    {
      if ((size = read(fd, buffer, READ_SIZE)) == 0)
	return ('\0');
      i = 0;
    }
  my_char = buffer[i];
  i++;
  size--;
  return (my_char);
}

char		*my_realloc_1(char *str)
{
  char		*new_str;
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  if ((new_str = malloc(sizeof(char) * (i + READ_SIZE + 1))) == NULL)
    return (NULL);
  new_str[i] = '\0';
  i = 0;
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  free(str);
  return (new_str);
}

char		*free_last_line(char *line)
{
  free(line);
  return (NULL);
}

char		*get_next_line(const int fd)
{
  char		*line;
  char		my_char;
  int		i;

  if ((line = malloc(sizeof(*line) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  line[0] = '\0';
  my_char = get_next_char(fd);
  i = 0;
  while (my_char != '\n' && my_char != '\0')
    {
      line[i] = my_char;
      my_char = get_next_char(fd);
      i++;
      if (i % (READ_SIZE) == 0)
	{
	  line[i] = '\0';
	  if ((line = my_realloc_1(line)) == NULL)
	    return (NULL);
	}
    }
  line[i] = '\0';
  return (my_char == '\0' && line[0] == '\0' ? free_last_line(line) : line);
}
