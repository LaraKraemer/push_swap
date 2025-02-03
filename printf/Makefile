# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:58:56 by lkramer           #+#    #+#              #
#    Updated: 2025/01/29 19:23:09 by lkramer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC          = cc 

CFLAGS      = -Wall -Wextra -Werror 

NAME        = libftprintf.a

TEST_EXEC   = test_printf

SRC         = \
				ft_printf.c \
				ft_print_char.c \
				ft_print_digit.c \
				ft_print_str.c \
				ft_print_unsigned_digit.c \
				ft_print_ptr.c \
				ft_print_hex.c \
          

# Object files - .c files
OBJ         = $(SRC:.c=.o)

# Default target
all: $(NAME)  $(TEST_EXEC)


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