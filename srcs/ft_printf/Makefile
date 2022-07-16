SRC_FILES = ft_printf			\
	  	ft_printf_utils 		\
		ft_printf_utils2 		\
		ft_is_arg				\
		ft_print_args ft_getflags \
		ft_print_precision 		\
		ft_print_prefix 		\
		ft_print_types 			\
		ft_print_types2 		\
		ft_first_arg 			\
		ft_check_arg			\


CC = gcc
AR = ar rc
CC_FLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBRARIES_DIR = ../../libraries/
NAME = $(LIBRARIES_DIR)ft_printf.a
INCLUDES = ../../includes/
OBJ_DIR = ../../objs/


SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(OBJ)

#$(NAME) : $(OBJ)
#	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
