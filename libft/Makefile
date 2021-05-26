# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 16:02:30 by cgangaro          #+#    #+#              #
#    Updated: 2021/04/27 10:56:12 by cgangaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
FLAGS 		= -Wall -Wextra -Werror -c
DEPS		= libft.h
SRCS		= 	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strlcpy.c \
				ft_strlcat.c \
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
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_strncpy.c \
				ft_zero.c \
				ft_strjoin_v2.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_add_char.c \
				ft_suprr_char.c \
				ft_search.c \
				ft_itoa_base.c \
				ft_strlen.c \
				ft_suppr_char_tab.c \
				ft_putstr_1.c \
				ft_putchar_1.c

OBJS = ${SRCS:%.c=%.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	gcc $(FLAGS) $< -o $@

clean:
			rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean all re
