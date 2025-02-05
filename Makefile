# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:05:03 by lkramer           #+#    #+#              #
#    Updated: 2025/02/05 21:29:57 by lkramer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc 

CFLAGS      = -Wall -Wextra -Werror 

NAME        = push_swap

LIBFT_DIR   = ./libft

LIBFT       = $(LIBFT_DIR)/libft.a


SRC         = \
				main.c \
				push_commands.c \
				error_handler.c \
				init_stack.c \
				radix_sort.c \
				sort_3_4_5.c \
				utils.c \

# Object files - .c files
OBJ         = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Create library  from object files
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile src file in out files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean: Remove .out files 
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean: Remove .out files & libary 
fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)

# Rebuild all
re:	fclean all

# Phony targets
.PHONY: all clean fclean re