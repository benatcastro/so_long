#---------NAMES--------------
UNAME		= $(shell uname)
NAME 		= so_long
LIB_NAME 	= 42lib.a
LIBFT 		= libft
GNL 		= gnl
PRINTF 		= ft_printf
#---------GCC and FLAGS----------

CC  		= gcc
AR			= ar rc
CFLAGS 		= -Wall -Wextra -Werror -g3
SANITIZE 	= -fsanitize=address -g3
VALGRIND 	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
MINILIB		= -framework openGL -framework AppKit -LLibraries/ -lmlx
LINUX_FLAGS	= -L.. -L%%/../lib -lXext -lX11 -lm -lbsd
#---------DIRECTORIES-----------
SRC_DIR = srcs/
PROJECT_DIR = ./srcs/so_long/
BONUS_SRC = ./srcs/so_long_bonus/
PROJECT_OBJS = $(OBJ_DIR)$(NAME)_objs/
OBJ_DIR = objs/
INC_DIR = -I includes/
BONUS_INC = -I includes_bonus/
LINUX_INC = -I includes/linux_includes
DARWIN_INC = -I includes/darwin_includes
LIB_DIR = libraries/

all: 42lib $(UNAME)

Linux: minilibx_linux

	@$(CC) $(CFLAGS) $(LINUX_FLAGS) $(PROJECT_DIR)*.c $(INC_DIR) $(LINUX_INC) -o $(NAME) $(LIB_DIR)*
	@echo "So Long Compiled"

Darwin: minilibx 42lib
	@$(CC) $(CFLAGS) $(MINILIB) $(PROJECT_DIR)*.c $(INC_DIR) $(DARWIN_INC) -o $(NAME) $(LIB_DIR)*
	@echo "So Long Compiled"

bonus:
	@$(CC) $(CFLAGS) $(SANITIZE) $(MINILIB) $(BONUS_SRC)*.c $(BONUS_INC) $(DARWIN_INC) -o $(NAME)_bonus $(LIB_DIR)*
	@echo "Bonus Darwin"

bonus_linux:
	@$(CC) $(CFLAGS) $(LINUX_FLAGS) $(PROJECT_DIR)*.c $(INC_DIR) $(BONUS_INC) -o $(NAME) $(LIB_DIR)*
	@echo "Bonus Linux"

sanitize: re
ifeq ($(UNAME), Linux)
	@$(CC) $(CFLAGS) $(SANITIZE) $(LINUX_FLAGS) $(BONUS_SRC)*.c $(INC_DIR) $(LINUX_INC) -o $(NAME) $(LIB_DIR)*
	@echo "Sanitize Linux"
else
	@$(CC) $(CFLAGS) $(SANITIZE) $(MINILIB) $(BONUS_SRC)*.c $(INC_DIR) $(DARWIN_INC) -o $(NAME) $(LIB_DIR)*
	@echo "Sanitize Darwin"
endif

run:
	@clear
	@./$(NAME) maps/map1.ber

valgrind: all
	@clear
	@$(VALGRIND) ./$(NAME) maps/map1.ber

42lib: libft gnl
	@$(AR) $(LIB_DIR)$(LIB_NAME) $(OBJ_DIR)*.o
	@ranlib $(LIB_DIR)$(LIB_NAME)
	@echo "42 Lib Compiled"

mk_dirs:
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(PROJECT_OBJS)
	@mkdir -p $(OBJ_DIR)

minilibx: mk_dirs
	@make -s --no-print-directory -C srcs/minilibx 2>logs

minilibx_linux: mk_dirs
	@make -s --no-print-directory -C srcs/minilibx-linux
	@echo "Minilib Linux Compiled"

libft: mk_dirs
	@make -s --no-print-directory -C srcs/libft
	@echo "Libft Compiled"

printf: mk_dirs libft
	@make -s --no-print-directory -C srcs/ft_printf
	@clear
	@echo "Printf Compiled"

gnl: mk_dirs
	@make -s --no-print-directory -C srcs/gnl
	@echo "GNL Compiled"

clean:
	@make clean -C srcs/libft
	@make clean -C srcs/ft_printf
	@make clean -C srcs/gnl
	@make clean -C srcs/minilibx
	@make clean -C srcs/minilibx-linux
	@rm -rf $(LIB_DIR)$(LIB_NAME)
	@rm logs
	@clear
	@echo "Clean done"

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIB_DIR)
	@rm so_long
	@rm so_long_bonus
	@echo "Fclean done"

re: fclean all

