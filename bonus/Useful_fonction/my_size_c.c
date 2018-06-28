/*
** my_size_c.c for  in /home/armin.pc/delivery/PSU_2016_my_printf/lib/my
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Sun Nov 20 08:06:12 2016 Enguerrand Arminjon
** Last update Sun Nov 20 08:07:41 2016 Enguerrand Arminjon
*/

int	my_size_c(int nb)
{
  int	size;

  size = 0;
  while (nb > 0)
    {
      nb = nb / 10;
      size++;
    }
  return (size);
}
