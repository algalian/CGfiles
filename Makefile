# **************************************************************************** #
#                                   MAKEFILE                                   #
# **************************************************************************** #

NAME		= matrix
CC			= gcc
CFLAGS		= -Wall -D BUFFER_SIZE=64
LIBS		= -lm

SRC			= main.c \
			  read_csv.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  write_csv.c \
			  

OBJ			= $(SRC:.c=.o)

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Build complete: $(NAME)$(RESET)"

%.o: %.c matrix.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled: $<$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re