.PHONY: all, $(NAME), clean, fclean, re



NAME = fdF

CC = gcc

#CFLAGS = -Wall -Werror -Wextra


LIBFT_DIR = sources/
HEADER_DIR = header/

SRC =  $(wildcard src/**/*.c)
OBJS = $(SRC:.c=.o)

INCLUDE = -I $(LIBFT_DIR) -I $(HEADER_DIR) -I ./mlx

#/*------------------------------------*\
#
#\*------------------------------------*/

FRAMEWORKS =  -framework OpenGL -framework AppKit


LMLX = ./mlx/libmlx.a
LIB = src/$(LIBFT_DIR)../libft.a


all: $(NAME)

$(NAME): $(OBJS)
	make -C src/$(LIBFT_DIR)../
	$(CC) -o $(NAME)  $(OBJS) $(CFLAGS) $(FRAMEWORKS)  $(LIB)  $(INCLUDE) $(LMLX)


#%.o: %.c
#	@gcc $(FLAG) -o $@ -c $<

clean:..
	@/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
	@/bin/rm -rf $(OBJS)


#	-I $(LIBFT_DIR)ft_library_header.h