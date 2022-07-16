SRC_FILES = ft_isalpha\
			ft_isdigit\
			ft_isalnum\
			ft_isascii\
			ft_isprint\
			ft_strlen\
			ft_strlcpy\
			ft_strlcat\
			ft_strncmp			\
			ft_toupper			\
			ft_tolower			\
			ft_strnstr			\
			ft_atoi				\
			ft_strchr			\
			ft_strrchr			\
			ft_memset			\
			ft_bzero			\
			ft_memchr			\
			ft_memcmp			\
			ft_memcpy			\
			ft_memmove			\
			ft_calloc			\
			ft_strdup			\
			ft_substr			\
			ft_strjoin			\
			ft_strtrim			\
			ft_split			\
			ft_itoa				\
			ft_strmapi			\
			ft_striteri		\
			ft_putchar_fd 		\
			ft_putstr_fd 		\
			ft_putendl_fd		\
			ft_putnbr_fd		\
			ft_lstadd_front_bonus \
			ft_lstlast_bonus     \
			ft_lstnew_bonus 		\
			ft_lstsize_bonus		\
			ft_lstadd_back_bonus 	\
			ft_lstdelone_bonus	\
			ft_lstclear_bonus		\
			ft_lstiter_bonus		\
			ft_lstmap_bonus




CC = gcc
AR = ar rc
CC_FLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBRARIES_DIR = ../../libraries/
NAME = $(LIBRARIES_DIR)libft.a
INCLUDES = ../../includes/
OBJ_DIR = ../../objs/


SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF = .cache_exists


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
