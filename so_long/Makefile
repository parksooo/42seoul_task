NAME		= so_long

CC			= cc
FLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./includes/
SRCS_DIR	= ./src/
LIB_DIR		= ./libft/
MLX_DIR		= ./mlx/

LIB_NAME	= ./libft/libft.a
INCS		= -I includes

SRC			=	 main.c error.c validation.c get_info.c init_function.c \
				chage_map_to_image.c keypressing.c get_next_line.c \
				bfs.c alloc_free_utils.c bfs_utils.c \
				bfs_utils2.c 
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))
OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(LIB_DIR) -lft -I $(INCS_DIR) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : fclean all
