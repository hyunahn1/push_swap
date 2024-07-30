NAME = libprintf.a

SRCS = ft_printf.c ft_plustype.c ft_print_base.c ft_print_char.c ft_print_denary.c ft_print_str.c ft_print_str.c ft_putstr.c ft_strlen.c ft_putchar.c

OBJS = ${SRCS:.c=.o}

AR = ar rcs

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $^
	${AR} ${NAME} $@

.PHONY: all clean fclean re bonus

all: ${NAME}

$(NAME): ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
