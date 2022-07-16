#
#

SRC_FILES_C=	mlx_shaders\
				mlx_png\
				mlx_xpm\
				mlx_int_str_to_wordtab\

SRC_FILES_M =	mlx_new_window\
				mlx_init_loop\
				mlx_new_image\
				mlx_mouse\

NAME = $(LIBRARIES_DIR)libmlx.a

CC = gcc
AR = ar rc
CC_FLAGS = -O2 -DSTRINGPUTX11
SRC_DIR_C = srcs_c/
SRC_DIR_M = srcs_m/
OBJ_DIR = ../objs/
LIBRARIES_DIR = ../libraries/
INCLUDES = ../includes/
# add to match string put with X11 in size and position
SRC_C = $(addprefix $(SRC_DIR_C), $(addsuffix .c, $(SRC_FILES_C)))
OBJ_C = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_C)))

SRC_M = $(addprefix $(SRC_DIR_M), $(addsuffix .m, $(SRC_FILES_M)))
OBJ_M = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_M)))

all: $(NAME)

$(NAME) : $(OBJ_C) $(OBJ_M)
	@$(AR) $(NAME) $(OBJ_C) $(OBJ_M)
	@ranlib $(NAME)
	@echo Minilib compiled
$(OBJ_DIR)%.o: $(SRC_DIR_C)%.c
	@$(CC) $(CC_FLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR_M)%.m
	@$(CC) $(CC_FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(NAME) $(OBJ_C) $(OBJ_M)
	@rm -f mlx_app

re: clean all
