/*
** my_strncmp for  in /home/armin.pc/delivery/CPool_Day06
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Oct 10 17:09:59 2016 Enguerrand Arminjon
** Last update Fri Mar 17 13:15:11 2017 Enguerrand Arminjon
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while ((i < nb - 1) && (s1[i] == s2[i])
	 && (s1[i] != '\0') && (s2[i] != '\0'))
    i = i + 1;
  return (s1[i] - s2[i]);
}
