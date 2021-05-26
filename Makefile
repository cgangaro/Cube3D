# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/01 15:34:49 by cgangaro          #+#    #+#              #
#    Updated: 2021/05/17 14:51:58 by cgangaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	Cub3D
MINILIBX 		=	libmlx.a
LIB				=	libft.a
SRC_PATH		=	srcs
SRCS_NAME		=   main.c \
					parsing.c \
					parsing_save_settings.c \
					parsing_save_settings_2.c \
					parsing_save_settings_3.c \
					parsing_map_verif.c \
					parsing_map_verif_2.c \
					parsing_verif_settings.c \
					parsing_verif_settings_2.c \
					parsing_opti_map.c \
					first.c \
					first_2.c \
					utils.c \
					screen_shoot.c \
					init_mlx.c \
					init_mlx_2.c \
					move.c \
					move_2.c \
					raycasting.c \
					raycasting_hit.c \
					vertical_line.c \
					sprite_raycasting.c \
					sprite_raycasting_2.c \
					init_main.c \
					parsing_tab_char.c \
					mini_map.c \
					life.c \
					life_2.c \
					secret_door.c \
					tri_tab.c \
					tri_tab_2.c \
					key.c \
					quit_and_error.c \

OBJS=${SRCS:.c=.o}

LIBRARIES		=	./libft/libft.a libmlx.dylib

CFLAGS			=	-Wall -Wextra -Werror -Ofast -flto -march=native -ffast-math \
					-I./includes\

GFLAGS			=	-Ofast -Wall -Wextra -Werror -lmlx -g3 \
					-I./includes\

SRCS 			=	$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

all:				$(NAME)

%.o: %.c ./includes/cube3d.h ./libft/libft.a libmlx.dylib
		$(CC) $(CFLAGS) -I ./includes/cube3d.h -c $< -o $@
$(NAME): $(MINILIBX) $(LIB) $(OBJS) ./includes/cube3d.h
			$(CC) $(OBJS) -L . $(GFLAGS) $(LIBRARIES) -o $(NAME) -lm
$(LIB):
	make -C libft all
$(MINILIBX):
	make -C minilibx all
	cp minilibx/libmlx.dylib ./

clean:
	make -C libft clean
	make -C minilibx clean
	rm -f $(OBJS)

norme:
	norminette srcs/${SRCS_NAME}

fclean:	clean
	make -C libft fclean
	rm -f $(NAME)
	rm libmlx.dylib

re:	fclean all

.PHONY:	all fclean clean re