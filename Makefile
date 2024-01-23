CC = cc

NAME = push_swap

NAME2 = checker

LIBFT = Libft/libft.a

SRC =	source/push_swap.c \
	source/err_check.c \
	source/print_stack.c \
	source/fill_stack.c \
	source/stack_utils.c \
	source/stack_utils2.c \
	source/swap.c \
	source/push.c \
	source/rotate.c \
	source/deal_2to5.c \
	source/move_and_print.c \
	source/create_index.c \
	source/lis.c \
	source/find_move.c \
	source/create_moves.c \
	source/execute_moves.c
	
BNS =   source_bonus/create_index_bonus.c \
	source_bonus/checker_bonus.c \
	source_bonus/err_check_bonus.c \
	source_bonus/print_stack_bonus.c \
	source_bonus/fill_stack_bonus.c \
	source_bonus/stack_utils_bonus.c \
	source_bonus/swap_bonus.c \
	source_bonus/push_bonus.c \
	source_bonus/rotate_bonus.c \
	source_bonus/operations_bonus.c \
	source_bonus/do_operations_bonus.c
	
OBJ = $(SRC:.c=.o)

OBJ_B = $(BNS:.c=.o)

FLAGS = -Wall -Werror -Wextra -g

all: libcomp $(NAME)

libcomp:
		@make -C Libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[92mpush_swap ready\033[0m"

bonus: $(OBJ_B)
	@make -C Libft
	$(CC) $(FLAGS) $(OBJ_B) $(LIBFT) -o $(NAME2)
	@echo "\033[92mchecker ready\033[0m"

libclean:
		@make clean -C Libft

clean:		libclean
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)

libfclean:
		@make fclean -C Libft

fclean:   	clean libfclean
		rm -rf $(NAME)
		rm -rf $(NAME2)
		@echo "\033[92mpush_swap removed\033[0m"
		
re: clean all

.PHONY: all re clean fclean bonus

.SILENT:

