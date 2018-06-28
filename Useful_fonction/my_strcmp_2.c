/*
** my_strcmp_2 for  in /home/armin.pc/delivery/CPool_Day06
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Oct 10 17:09:59 2016 Enguerrand Arminjon
** Last update Wed Mar  8 11:11:37 2017 Enguerrand Arminjon
*/

int	my_strcmp_2(char *s1, char *s2, char sep)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i])
    i++;
  if (s1[i] == sep && s2[i] == '\0')
    return (0);
  return (1);
}
