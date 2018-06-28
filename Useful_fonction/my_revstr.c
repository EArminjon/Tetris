/*
** my_revstr.c for  in /home/armin.pc/delivery/CPool_Day06
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Oct 10 12:54:24 2016 Enguerrand Arminjon
** Last update Fri Oct 14 14:29:03 2016 Enguerrand Arminjon
*/

char	*my_revstr(char *str)
{
  int	i;
  char	x;
  int	n;

  i = 0;
  n = 0;
  while (str[n] != '\0')
    {
      n = n + 1;
    }
  n = n - 1;
  while (n > i)
    {
      x = str[i];
      str[i] = str[n];
      str[n] = x;
      i = i + 1;
      n = n - 1;
    }
  return (str);
}
