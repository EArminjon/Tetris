##
## Makefile for  in /home/armin.pc/delivery/PSU_2016_minishell1
##
## Made by Enguerrand Arminjon
## Login   <armin.pc@epitech.net>
##
## Started on  Mon Jan  2 11:32:58 2017 Enguerrand Arminjon
## Last update Fri Mar 17 09:09:09 2017 Enguerrand Arminjon
##

SRCS 	=	Useful_fonction/my_putstr.c			\
		Useful_fonction/my_putchar.c			\
		Useful_fonction/my_put_nbr.c			\
		Useful_fonction/my_getnbr.c			\
		Useful_fonction/my_revstr.c			\
		Useful_fonction/my_printf.c			\
		Useful_fonction/my_printf2.c			\
		Useful_fonction/my_printf3.c			\
		Useful_fonction/my_printf4.c			\
		Useful_fonction/my_put_short.c			\
		Useful_fonction/my_put_long.c			\
		Useful_fonction/print_tab.c			\
		Useful_fonction/my_strcat.c			\
		Useful_fonction/my_strcmp.c			\
		Useful_fonction/my_strcmp_2.c			\
		Useful_fonction/my_str_isalpha.c		\
		Useful_fonction/my_str_isnum.c			\
		Useful_fonction/free_my_tab.c			\
		Useful_fonction/free_tab.c			\
		Useful_fonction/my_realloc.c			\
		Useful_fonction/get_next_line.c			\
		Useful_fonction/my_puterror.c			\
		Useful_fonction/my_intlen.c			\
		Useful_fonction/int_to_str.c			\
		Useful_fonction/my_strstr.c			\
		Useful_fonction/my_strncmp.c			\
		Source/fonction_for_structure_debug.c 		\
		Source/second_fonction_for_structure_debug.c 	\
		Source/shape_tetrimino.c			\
		Source/structure_debug.c			\
		Source/my_put_in_tab.c				\
		Source/pointeur_sur_fonction.c			\
		Source/my_strcut.c				\
		Source/malloc_for_name_tetrimino.c		\
		Source/my_copy_tab.c				\
		Source/ncurses_game.c				\
		Source/malloc_tab.c				\
		Source/random.c					\
		Source/my_strcat_custom.c			\
		Source/move_left_right_shape.c			\
		Source/map_ncurses_tetris.c			\
		Source/rotate_shape.c				\
		Source/fonction_for_rotate_shape.c		\
		Source/load_shape.c				\
		Source/fall_shape.c				\
		Source/delete_line.c				\
		Source/free_tab_and_return.c			\
		Source/check_my_envp.c				\
		Source/my_capacities.c				\
		Source/check_win_check_cmds.c			\
		Source/build_convert_map.c			\
		Source/display_game_over_file_leaderboard.c	\
		Source/is_a_tetri_file.c			\
		Source/chained_list.c				\
		Source/help.c					\
		Source/my_name.c				\
		Source/load_color.c				\
		Source/enlarge_map.c				\
		Source/display_debug_screen.c			\
		Source/main.c

OBJS 	=  	$(SRCS:.c=.o)

CFLAGS 	+=	-I include -Wall -Wextra

LDFLAGS +=	-I include -lncurses

NAME 	=	tetris

CC	= 	gcc

$(NAME): 	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
