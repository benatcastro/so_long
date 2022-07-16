SRC_FILES = get_next_line_bonus			\
	  		get_next_line_utils_bonus 		\


CC = gcc
AR = ar rc
CC_FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
RM = rm -f
LIBRARIES_DIR = ../../libraries/
NAME = $(LIBRARIES_DIR)gnl.a
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

.PHONY: all clean fclean re bonus
