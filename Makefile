# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:05:03 by lkramer           #+#    #+#              #
#    Updated: 2025/01/20 15:43:51 by lkramer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc 

CFLAGS      = -Wall -Wextra -Werror 

NAME        = push_swap.a

TEST_EXEC   = push_swap.a

SRC         = \
				push_swap.c \
				commands.c \
				utils.c \

# Object files - .c files
OBJ         = $(SRC:.c=.o)

# Default target
all: $(NAME)  $(TEST_EXEC)

# Testing
TEST_SRC    = main.c
TEST_OBJ    = $(TEST_SRC:.c=.o)

# Test: Build and run the test program
test: $(NAME) $(TEST_EXEC)
	./$(TEST_EXEC)

# Create test executable
$(TEST_EXEC): $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) $(NAME)


# Create library  from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 

# Compile src file in out files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean: Remove .out files 
clean:
	rm -f $(OBJ)  $(TEST_OBJ)

# Full clean: Remove .out files & libary 
fclean:	clean
	rm -f $(NAME)  $(TEST_EXEC)

# Rebuild all
re:	fclean all

# Phony targets
.PHONY: all clean fclean re test