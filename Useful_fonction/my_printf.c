/*
** my_printf.c for  in /home/armin.pc/delivery/PSU_2021_my_printf_boostrap
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Nov  8 17:28:41 2016 Enguerrand Arminjon
** Last update Thu Jan  5 10:51:53 2017 Enguerrand Arminjon
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

void		my_nonprintable(char *str)
{
  int		i;

  i = 0;
  while (str[i + 1] != '\0')
    {
      if (str[i] >= 32 && str[i] < 127)
	my_putchar(str[i]);
      else if ((str[i] < 32 && str[i] >= 0) || (str[i] == 127))
	{
	  my_putchar('\\');
	  if (str[i] == 0)
	    my_putstr("000");
	  else if (str[i] >= 1 && str[i] <= 7)
	    my_putstr("00");
	  else if (str[i] > 7 && str[i] < 64)
	    my_putchar('0');
	  my_octal(str[i]);
	}
      i++;
    }
}

void		the_specifier_2(char *s, va_list ap, int *a)
{
  *a = *a + 1;
  if (s[*a - 1] == 'h' && s[*a] == 'd')
    my_put_short(va_arg(ap, int));
  if (s[*a - 1] == 'l' && s[*a] == 'd')
    my_put_long(va_arg(ap, unsigned long));
}

void		c_and_u(char *s, va_list ap, int *a)
{
  if (s[*a] == 'c')
    my_putchar(va_arg(ap, int));
  else if (s[*a] == 'u')
    my_put_nbr(va_arg(ap, unsigned int));
  else if (s[*a] == 'p')
    {
      my_putstr("0x");
      my_hexadecimal_2(va_arg(ap, long int));
    }
}

void		the_specifier(char *s, va_list ap, int *a)
{
  if (s[*a] == 'c' || s[*a] == 'u' || s[*a] == 'p')
    c_and_u(s, ap, a);
  else if (s[*a] == 's')
    my_putstr(va_arg(ap, char *));
  else if (s[*a] == 'd' || s[*a] == 'i')
    my_put_nbr(va_arg(ap, long int));
  else if (s[*a] == '%')
    my_putchar('%');
  else if (s[*a] == 'o')
    my_octal(va_arg(ap, unsigned int));
  else if (s[*a + 1] <= 'z' && s[*a + 1] >= 'a')
    the_specifier_2(s, ap, a);
  else if (s[*a] == 'X')
    my_hexadecimal(va_arg(ap, unsigned int));
  else if (s[*a] == 'x')
    my_hexadecimal_2(va_arg(ap, unsigned int));
  else if (s[*a] == 'b')
    my_binari(va_arg(ap, unsigned int));
  else if (s[*a] == 'S')
    my_nonprintable(va_arg(ap, char *));
  else if (s[*a] == 'p')
    my_hexadecimal_2(va_arg(ap, long int));
  else
    the_else_print(a);
}

int		my_printf(char *s, ...)
{
  va_list	ap;
  int		a;

  a = 0;
  va_start(ap, s);
  while (s[a] != '\0')
    {
      if (s[a] == '%')
	{
	  a = a + 1;
	  while (s[a] == ' ')
	    a = a + 1;
	  if (s[a] == '-' || s[a] == '+' || s[a - 1] == ' ' || s[a] == '#'
	      || s[a] == '0' || (s[a] <= '9' && s[a] >= '1') || s[a] == '*')
	    the_flags(s, ap, &a);
	  the_specifier(s, ap, &a);
	}
      else
	my_putchar(s[a]);
      a = a + 1;
    }
  va_end(ap);
  return (0);
}
