#.c: files in C language
#.o: files transformed into machine language(binary)
#Compilation Process: Check README.md

CC = cc
CFLAGS += -Wall -Wextra -Werror 
AR = ar -rc
RM = rm -rf
Name = libftprintf.a
SRCS = ft_printf.c ft_print_character.c
OBJS = ft_printf.o ft_print_character.o
Test = test
#test is the excutable's name. Note that there's no file extension for excutables on Unix-like system


all:$(Test)

$(Test):$(Name) test.o
	$(CC) test.o $(Name) -o $(Test)

$(Name):$(OBJS)
	$(AR) $(Name) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean:clean
	$(RM) $(Name) $(Test)

re:fclean all