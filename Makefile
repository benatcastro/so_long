#---------NAMES--------------
NAME 		= so_long
LIB_NAME 	= 42lib.a
LIBFT 		= libft
GNL 		= gnl
PRINTF 		= ft_printf
#---------GCC and FLAGS----------

CC  		= gcc
AR		= ar rc
CFLAGS 		= -Wall -Wextra -Werror
SANITIZE 	= -fsanitize=address -g3
VALGRIND 	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
MINILIB		= -framework openGL -framework AppKit -lmlx
LINUX_FLAGS	= -L.. -L%%/../lib -lXext -lX11 -lm -lbsd
#---------DIRECTORIES-----------
SRC_DIR = srcs/
PROJECT_DIR = srcs/so_long/
OBJ_DIR = objs/
INC_DIR = -I includes/
LINUX_INC = -I includes/linux_includes
LIB_DIR = libraries/


#---------------PREFIX and SUFFIX-----------------

SRC_LIBFT = $(addprefix $(SRC_DIR)libft/, $(addsuffix .c, $(FILES_LIBFT)))
OBJ_LIBFT = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_LIBFT)))

all: linux

linux: minilibx_linux 42lib
	@$(CC) $(CFLAGS) $(LINUX_FLAGS) $(PROJECT_DIR)*.c $(INC_DIR) $(LINUX_INC) -o $(NAME) $(LIB_DIR)*
	@echo "So Long Compiled"

mac-os: minilibx 42lib
	@$(CC) $(CFLAGS) $(MINILIB) $(PROJECT_DIR)* -I $(INC_DIR)  -o $(NAME) $(LIB_DIR)*
	@echo "So Long Compiled"


run: all
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
	@mkdir -p $(OBJ_DIR)

minilibx: mk_dirs
	@make -s --no-print-directory -C srcs/minilibx

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
	@rm -rf $(NAME)
	@clear
	@echo "Clean done"

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIB_DIR)
	@echo "Fclean done"
re: clean all
