/*
** destroy_music.c for  in /home/armin.pc/delivery/PSU_2016_tetris
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Mar  8 11:08:02 2017 Enguerrand Arminjon
** Last update Wed Mar  8 11:12:24 2017 Enguerrand Arminjon
*/

#include <ncurses.h>
#include <SFML/Audio.h>
#include "tetris.h"

int	destroy_music(t_tetris *tetris)
{
  sfMusic_destroy(tetris->music[0]);
  sfMusic_destroy(tetris->music[1]);
  sfMusic_destroy(tetris->music[2]);
  sfMusic_destroy(tetris->music[3]);
  endwin();
  return (0);
}
