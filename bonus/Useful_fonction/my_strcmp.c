/*
** my_strcmp for  in /home/armin.pc/delivery/CPool_Day06
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Oct 10 17:09:59 2016 Enguerrand Arminjon
** Last update Mon Jan 16 14:09:15 2017 Enguerrand Arminjon
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') &&(s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}
