NAME = libftprintf.a

INC = ft_printf.h

RAW_SRCS=\
			 ft_printf.c \
			 ft_itoa_base.c \
			 ft_itoa_base2.c \
			 ft_put.c\
			 ft_put2.c\
			 ft_itoa_base3.c\
			 ft_find.c\
			 ft_flags1.c\
			 ft_flags2.c\
			 ft_flags3.c\
			 libft/ft_strlen.c\
			 libft/ft_strdup.c\
			 libft/ft_calloc.c\

OBJS = $(RAW_SRCS:.c=.o)


CC = gcc
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
		@$(CC) $(CFLAG) -c $^ -o $@ -I $(INC)

$(NAME): $(OBJS)
		@ar -rc $(NAME) $(OBJS) $@ $^
			@ranlib $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
