/*
** my_intlen.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Feb 22 16:10:48 2017 Enguerrand Arminjon
** Last update Wed Feb 22 16:11:58 2017 Enguerrand Arminjon
*/

int	my_intlen(int nb)
{
  int	i;

  i = 0;
  while (nb > 0)
    {
      nb = nb / 10;
      i++;
    }
  return (i);
}
