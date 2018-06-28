/*
** my_str_isalpha.c for  in /home/armin.pc/delivery/CPool_Day07/lib/my
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Oct 12 08:50:53 2016 Enguerrand Arminjon
** Last update Tue Jan 17 13:34:17 2017 Enguerrand Arminjon
*/

int	my_str_isalpha(char *str)
{
  int	i;
  int	end;

  end = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0') || (str[i] > '9' && str[i] < 'A')
	  || (str[i] > 'Z' && str[i] < '_') || (str[i] > '_' && str[i] < 'a')
	  || (str[i] > 'z'))
	end = 1;
      i++;
    }
  return (end);
}
