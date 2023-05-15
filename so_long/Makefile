# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 08:04:49 by wcorrea-          #+#    #+#              #
#    Updated: 2023/05/15 22:31:58 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = so_long

SRC = src/main.c src/utils.c src/create_map.c src/clean_exit.c \
		src/check_map.c src/graphics.c src/moves.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = lib/libft
MLX_PATH = lib/mlx
LIBFT = -L ${LIBFT_PATH} -lft
MLX	= -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm 

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(OUT): ${OBJS}
		${MAKE} ${LIBFT_PATH}
		${MAKE} ${MLX_PATH}
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${OUT}

all:	${OUT}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${MAKE} ${MLX_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${OUT}

re: fclean all

.PHONY: all clean fclean re