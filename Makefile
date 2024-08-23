#To test the functions, there's No CFLAGS in this Makefile
#.c: files in C language
#.o: files transformed into machine language(binary)
#Compilation Process: Check README.md

CC = cc
AR = ar rcs

SRCS = ft_printf.c ft_print_character.c ft_print_digit.c ft_print_pointer.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
TEST = test

all: $(TEST)

$(TEST): $(NAME) test.o
	$(CC) test.o $(NAME) -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) test.o

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all
