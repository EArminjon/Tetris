/*
** my_strcpy.c for  in /home/armin.pc/delivery/CPool_Day06
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Oct 10 12:54:24 2016 Enguerrand Arminjon
** Last update Mon Jan 30 16:23:54 2017 Enguerrand Arminjon
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  src[i] = '\0';
  return (dest);
}
