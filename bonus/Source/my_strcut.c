/*
** my_strcut.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Feb 22 18:11:39 2017 Enguerrand Arminjon
** Last update Wed Feb 22 18:12:02 2017 Enguerrand Arminjon
*/

char	*my_strcut(char *str, char sep)
{
  int	i;

  i = 0;
  while (str[i] != sep && str[i] != '\0')
    i++;
  str[i] = '\0';
  return (str);
}
