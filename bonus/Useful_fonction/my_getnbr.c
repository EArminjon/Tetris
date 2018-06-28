/*
** my_getnbr.c for  in /home/armin.pc
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Fri Oct 14 14:43:00 2016 Enguerrand Arminjon
** Last update Thu Mar 16 09:12:56 2017 Enguerrand Arminjon
*/

int	my_getnbr(char *str)
{
  int	rslt;
  int	o;
  int	signe;

  rslt = 0;
  signe = 1;
  o = 2147483647;
  while (*str == '+' || *str == '-')
    {
      if (*str == '-')
	signe = -signe;
      str++;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9' && rslt <= o && rslt > -o)
    {
      if (rslt > 2147483647 || rslt < -2147483647)
	return (0);
      rslt = rslt * 10 + *str - 48;
      str++;
    }
  if (signe == -1)
    rslt = -rslt;
  return (rslt);
}
