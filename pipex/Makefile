NAME 		= pipex

CC 			= cc
FLAGS 		= -Wall -Wextra -Werror

SRC_DIR		= ./mandatory/srcs/
BSRC_DIR	= ./bonus/srcs/
LIB_DIR		= ./libft/
LIB_NAME	= libft.a

SRC 		= 	main.c error.c utils.c pipex.c sed_utils.c
BSRC		=	bonus_error.c bonus_execve.c bonus_main.c bonus_pipex.c bonus_utils.c \
				heredoc_utils.c get_next_line.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
BSRCS		=	$(addprefix $(BSRC_DIR), $(BSRC))
OBJS		=	$(SRCS:%.c=%.o)
BOBJS 		= 	$(BSRCS:%.c=%.o)

ifdef PIPEX_WITH_BONUS
	INC_DIR = ./bonus/includes/
    OBJ_FILES = $(BOBJS)
else
	INC_DIR = ./mandatory/includes/
    OBJ_FILES = $(OBJS)
endif

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_DIR)

all : $(NAME)

bonus :
	make PIPEX_WITH_BONUS=1 all
	
$(NAME) : $(OBJ_FILES)
	make -C $(LIB_DIR)
	$(CC) $(FLAGS) $^ -Llibft -lft -o $@

clean :
	make -C $(LIB_DIR) clean
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re : 
	make fclean
	make all

bonus_re :
	make fclean
	make bonus 

.PHONY: all bonus clean fclean re bre