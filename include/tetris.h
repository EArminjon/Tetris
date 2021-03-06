/*
** tetris.h for  in /home/armin.pc
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Nov  7 11:32:08 2016 Enguerrand Arminjon
** Last update Thu Mar 16 09:38:19 2017 Enguerrand Arminjon
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# include <SFML/Audio.h>
# include <ncurses.h>
# include <time.h>

typedef struct		s_fall
{
  char			**shape;
  int			high;
  int			weight;
  int			color;
}			t_fall;

typedef struct		s_time
{
  clock_t		start;
  clock_t		time_level;
  clock_t		now;
  int			my_time;
}			t_time;

typedef struct		s_debug
{
  int			help;
  char			*num;
  int			level;
  char			*left;
  char			*right;
  char			*top;
  char			*drop;
  char			*quit;
  char			*pause;
  int			row;
  int			col;
  char			*w_next;
  char			*debug;
  int			nb_tetri;
}			t_debug;

typedef struct		s_tetris
{
  t_debug		*t_debug;
  int			d;
  char			*term;
  int			nb_good_shape;
  int			rn;
  int			cn;
  int			max_high;
  int			max_weight;
  int			first;
  int			end;
  int			high_score;
  int			score;
  int			line;
  int			keys;
  int			f_next;
  t_time		*time;
  t_fall		*fall_copy;
}			t_tetris;

typedef struct		s_d_shape
{
  char			**my_tab;
  int			weight;
  int			high;
  int			color;
}			t_d_shape;

typedef struct		s_shape
{
  char			**map;
  int			high;
  int			weight;
  int			color;

  struct s_shape	*next;
}			t_shape;

typedef struct		s_rotate
{
  int			first_col;
  int			last_col;
  int			first_row;
  int			last_row;
  int			high;
  int			weight;
  int			a;
  int			b;
}			t_rotate;

#endif /* !TETRIS_H_ */
