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

Darwin: 42lib minilibx
	@$(CC) $(CFLAGS) $(MINILIB) $(PROJECT_DIR)*.c $(INC_DIR) $(DARWIN_INC) -o execs/$(NAME) $(LIB_DIR)*
	@echo "$(BLUE)🎮So_long for Darwin Compiled🎮"
	@echo "$(PURPLE)( つ ◕_◕ )つGiv 125( つ ◕_◕ )つ$(RESET)"

bonus: 42lib minilibx mk_dirs
	@$(CC) $(CFLAGS) $(SANITIZE) $(MINILIB) $(BONUS_SRC)*.c $(BONUS_INC) $(DARWIN_INC) -o execs/$(NAME)_bonus $(LIB_DIR)*
	@echo "$(BLUE)🎮So_long bonus for Darwin Compiled🎮"
	@echo "$(PURPLE)( つ ◕_◕ )つGiv 125( つ ◕_◕ )つ$(RESET)"

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

run: all
	@clear
	@./execs/$(NAME) maps/map1.ber

run_bonus: bonus
	@clear
	@./execs/$(NAME)_bonus maps/bonus_map.ber

valgrind: all
	@clear
	@$(VALGRIND) ./$(NAME) maps/map1.ber

42lib: libft gnl
	@$(AR) $(LIB_DIR)$(LIB_NAME) $(OBJ_DIR)*.o
	@ranlib $(LIB_DIR)$(LIB_NAME)
	@echo "$(GREEN)42 Lib Compiled 📚$(RESET)"

mk_dirs:
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(PROJECT_OBJS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p execs/

minilibx: mk_dirs
	@make -s --no-print-directory -C srcs/minilibx 2>logs
	@echo "$(GREEN)Minilib Darwin Compiled 🎨$(RESET)"

minilibx_linux: mk_dirs
	@make -s --no-print-directory -C srcs/minilibx-linux
	@echo "$(GREEN)Minilib Linux Compiled 🎨$(RESET)"

libft: mk_dirs
	@make -s --no-print-directory -C srcs/libft
	@echo "$(GREEN)Libft Compiled 📚$(RESET)"

printf: mk_dirs libft
	@make -s --no-print-directory -C srcs/ft_printf
	@clear
	@echo "Printf Compiled 📚"

gnl: mk_dirs
	@make -s --no-print-directory -C srcs/gnl
	@echo "$(GREEN)GNL Compiled 📚$(RESET)"

norme:
	@norminette srcs/so_long & norminette srcs/so_long_bonus
	@norminette includes/textures.h & norminette includes/so_long.h & includes/darwin_includes/keys.h
	@norminette srcs/so_long & norminette srcs/so_long_bonus
clean:
	@make clean -C srcs/libft
	@make clean -C srcs/ft_printf
	@make clean -C srcs/gnl
	@make clean -C srcs/minilibx
	@make clean -C srcs/minilibx-linux
	@rm -rf $(LIB_DIR)$(LIB_NAME)
	@rm logs
	@clear
	@echo "$(YELLOW)Clean done 🗑️$(RESET)"

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIB_DIR)
	@rm -rf execs/
	@echo "$(YELLOW)Fclean done 🗑️$(RESET)"

re: fclean all

BLACK		:= $(shell tput -Txterm setaf 0)
RED			:= $(shell tput -Txterm setaf 1)
GREEN		:= $(shell tput -Txterm setaf 2)
YELLOW		:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
PURPLE		:= $(shell tput -Txterm setaf 5)
BLUE		:= $(shell tput -Txterm setaf 6)
WHITE		:= $(shell tput -Txterm setaf 7)
RESET		:= $(shell tput -Txterm sgr0)
