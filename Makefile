#.c: files in C language
#.o: files transformed into machine language(binary)
#Compilation Process: Check README.md

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_printf.c ft_print_character.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
TEST = test

all: $(NAME) $(TEST)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(TEST): $(NAME) test.o
	$(CC) $(CFLAGS) -o $(TEST) test.o $(NAME)

clean:
	rm -f $(OBJS) test.o

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all
