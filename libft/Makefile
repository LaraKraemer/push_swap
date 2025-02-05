# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 18:10:29 by lkramer           #+#    #+#              #
#    Updated: 2025/02/04 10:50:21 by lkramer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc 

CFLAGS      = -Wall -Wextra -Werror

NAME        = libft.a

SRC         = \
            ft_strlen.c \
            ft_strlcat.c \
            ft_isalpha.c \
            ft_isdigit.c \
            ft_isalnum.c \
            ft_isascii.c \
            ft_isprint.c \
            ft_memset.c \
            ft_strncmp.c \
            ft_bzero.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_strlcpy.c \
            ft_toupper.c \
            ft_tolower.c \
            ft_strchr.c \
            ft_strrchr.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_strnstr.c \
            ft_atoi.c \
            ft_calloc.c \
            ft_strdup.c \
            ft_substr.c \
            ft_strjoin.c \
            ft_strtrim.c \
            ft_split.c \
            ft_itoa.c \
            ft_strmapi.c \
            ft_striteri.c \
            ft_putchar_fd.c \
            ft_putstr_fd.c \
            ft_putendl_fd.c \
            ft_putnbr_fd.c \
			ft_print_char.c \
			ft_print_digit.c \
			ft_print_hex.c \
			ft_print_ptr.c \
			ft_print_str.c \
			ft_print_unsigned_digit.c \
			ft_printf.c \


# Object files - .c files
OBJ         = $(SRC:.c=.o)

BONUS       = \
            ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \

BONUS_OBJ   = $(BONUS:.c=.o)

# Default target
all: $(NAME)

# Create library  from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 

# Compile src file in out files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean: Remove .out files 
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Full clean: Remove .out files & libary 
fclean:	clean
	rm -f $(NAME) $(BONUS_OBJ)

# Rebuild all
re:	fclean all

bonus: $(NAME) $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ) 


# Phony targets
.PHONY: all clean fclean re bonus 
