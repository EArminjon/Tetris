/*
** my.h for  in /home/armin.pc/delivery/CPool_Day09/include
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Fri Oct 14 08:36:11 2016 Enguerrand Arminjon
** Last update Sat Mar 18 17:08:11 2017 Enguerrand Arminjon
*/

#ifndef MY_H_
# define MY_H_

# include <sys/types.h>
# include <stdarg.h>
# include "tetris.h"

/*
** Project's functions with ncurses
*/

void	display_sequence(char *str);
int	print_tetris_title();
void	speed_of_the_game(t_tetris *tetris);
int	the_leaderboard_game();
int	do_option(int l, t_tetris *tetris, int row, int col);
void	load_color();
void	enlarge_map(int row, int col, t_tetris *tetris);
int	destroy_music(t_tetris *tetris);
int	do_action(int l, int i, t_tetris *tetris);
int	display_game_over_file_leaderboard(t_tetris *tetris, int nb);
int	display_menu();
char	**game_cmds(char **tetrimap, t_tetris *tetris, t_fall *fall, char *s);
int	check_game(char **tetri_map);
char	**my_drop_shape(char **tetri_map, t_tetris *tetris);
char	**free_tab_return(char **free_tab, char **return_tab);
char	**convert_for_rotate(char **copy);
int	find_first_row_shape(char **tetri_map);
int	find_last_row_shape(char **tetri_map, int size);
int	find_first_col_shape(char **tetri_map);
int	find_last_col_shape(char **tetri_map, t_tetris *tetris);
char	**fall_shape_one_line(char **tetri_map, t_tetris *tetris);
char	**load_shape(t_fall *fall, t_shape *shape, t_tetris *tetris);
char	**load_shape_on_top(t_fall *fal, char **map, t_tetris *tet, int j_zer);
char	**my_delete_line(char **tetri_map, int line, t_tetris *tetris, int i);
char	**my_rotate_shape(char **tetri_map, t_tetris *tetris, t_fall *fall);
void	display_game();
char	**convert_map(char **tetri_map);
char	**init_map_game(char **map, t_tetris *tetris, int zero);
char	**move_my_shape_left(char **map, t_tetris *tetris, t_fall *fall);
char	**move_my_shape_right(char **map, t_tetris *tetris, t_fall *fall);

/*
** Project's functions without ncurses
*/

void	display_debug_screen(t_tetris *tetris);
char	**my_cut_tab(char **my_tab);
char	*press_any_key(int reset, int on_one, int off_zero, int j);
int	display_list_tetri(t_shape *shape, t_tetris *tetris);
void	free_list_tetri(t_shape *shape);
int	chained_list(t_shape *shape, t_shape *new, char **my_tab, t_tetris *t);
char	*my_name(char *str);
int	is_a_tetri_file(char *str);
int	my_capacities(t_tetris *tetris);
int	check_my_envp(t_tetris *tetris, char **envp);
int	my_tetris_help(char **av, int *i, t_tetris *tetris);
char	*my_strcat_custom(char *copy, char *str, char sep);
int	count_col(char **my_tab);
int	count_row(char **my_tab);
int	my_random(int min, int max);
char	**malloc_tab(char **map, int row, int col);
int	display_ncurses(t_shape *shape, t_tetris *tetris);
char	**my_copy_tab(char **new, char **my_tab);
int	my_check_tetrimino(char *str, int debug, t_shape *shape, t_tetris *t);
char	**order_my_tab(char **my_tab);
char	**malloc_for_name_tetrimino(char **my_tab);
char	*my_strcut(char *str, char sep);
int	confront_all_key(t_tetris *tetris);
int	k_key(char **av, int *i, t_tetris *tetris);
char	*find_nb_in_str(char *str);
char	**my_put_in_tab(t_d_shape *shape, int fd);
int	display_flag_h(char **av, int *i, t_tetris *tetris);
char	**display_tetriminos();
char	*find_cmds(char *str, char sep);
int	init_struct_prompt(t_tetris *tetris, int ac, char **av);
int	init_struct(t_tetris *tetris);
int	d_debug(char **av, int *i, t_tetris *tetris);
int	l_num(char **av, int *i, t_tetris *tetris);
char	*find_nb(char *str, char sep);
int	map_size(char **av, int *i, t_tetris *tetris);
int	w_without(char **av, int *i, t_tetris *tetris);
char	*get_next_line(int fd);

/*
** Other functions
*/

char	*int_to_str(int nb);
int	my_intlen(int nb);
void	print_tab(char **my_tab);
int	my_put_base(int nb);
int	my_puterror(char *str, int canal, int ret);
char	**free_tab(char **my_tab);
char	my_strcmp_2(char *str_1, char *str_2, char sep);
char	my_strcmp(char *str_1, char *str_2);
char	my_strncmp(char *str_1, char *str_2, int nb);
char	my_strcpy(char *str_1, char *str_2);
char	*my_strcat(char *dest, char *src);
char	*my_realloc(char *str, int new_size);
void	for_my_pitch(int i, int zero);
int	my_size_c(int nb);
void	the_hashtag(char *s, va_list ap, int *a);
void	the_else_print(int *a);
void	the_flags(char *s, va_list ap, int *a);
void	my_octal(long int nb);
int	my_put_short(short nb);
int	my_printf(char *s, ...);
int	my_size(int nb);
void	my_binari(int nb);
void	my_hexadecimal(long int nb);
void	my_hexadecimal_2(long int nb);
int	my_putstr_int(int *str);
int	my_put_long(long int nb);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_revstr(char *str);
int	my_strstr(char *str, char *to_find);
int	my_str_isnum(char *str);

#endif /* !MY_H_ */
