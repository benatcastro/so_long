#---------NAMES--------------
UNAME		= $(shell uname)
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
PROJECT_DIR = ./srcs/so_long/
PROJECT_OBJS = $(OBJ_DIR)$(NAME)_objs/
OBJ_DIR = objs/
INC_DIR = -I includes/
LINUX_INC = -I includes/linux_includes
LIB_DIR = libraries/



#---------------PROJECT_FILES---------------------
FILES_SO_LONG = hooks			\
				main			\
				map_checker		\
				mlx_load_images	\
				print_errors	\
				render_fncs		\

#---------------PREFIX and SUFFIX-----------------

SRC = $(addprefix $(PROJECT_DIR), $(addsuffix .c,  $(FILES_SO_LONG)))
OBJ = $(addprefix $(PROJECT_OBJS), $(addsuffix .o, $(FILES_SO_LONG)))

all: 42lib $(UNAME)
#$(TEST): $(OBJ)
#	@echo "hey"

#$(PROJECT_OBJS)%.o  : $(SRC)%.c
#	echo "heyd"
#	(CC) $(CFLAGS) $(INCLUDES) $(LINUX_FLAGS) $(INC_DIR) $(LINUX_INC) $(LIB_DIR)*.a -c $< -o $@
#	@bash scripts/main

Linux: minilibx_linux

#$(NAME): $(OBJ)
#	$(PROJECT_OBJS): $(SRC)
#		$(CC) $(CFLAGS) $(INCLUDES) $(LINUX_FLAGS) $(INC_DIR) $(LINUX_INC) $(LIB_DIR)*.a -c $< -o $@
#	echo $(SRC_SO_LONG)
	@$(CC) $(CFLAGS) $(LINUX_FLAGS) $(PROJECT_DIR)*.c $(INC_DIR) $(LINUX_INC) -o $(NAME) $(LIB_DIR)*
	@echo "So Long Compiled"

Darwin: minilibx 42lib
	@$(CC) $(CFLAGS) $(MINILIB) $(PROJECT_DIR)*.c $(INC_DIR) -o $(NAME) $(LIB_DIR)*
	@echo "So Long Compiled"

sanitize: re
ifeq ($(UNAME), Linux)
	@$(CC) $(CFLAGS) $(SANITIZE) $(LINUX_FLAGS) $(PROJECT_DIR)*.c $(INC_DIR) $(LINUX_INC) -o $(NAME) $(LIB_DIR)*
	@echo "Sanitize Linux"
else
	@$(CC) $(CFLAGS) $(SANITIZE) $(MINILIB) $(PROJECT_DIR)*.c $(INC_DIR) -o $(NAME) $(LIB_DIR)*
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

clean_test:
	@rm -rf so_long

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIB_DIR)
	@echo "Fclean done"
re: clean_test all
