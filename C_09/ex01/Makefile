.SUFFIXES = .c .o

SOURCES = srcs/
HEADERS = includes/

tOBJS = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
OBJS = $(addprefix $(SOURCES), $(tOBJS))
#SRCS = $(OBJS: .o=.c)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar -rcusv $(TARGET) $^

%.o : %.c
	$(CC) -c -o $@ $(CFLAGS) -I$(HEADERS) $< 
#srcs/ft_putchar.o : srcs/ft_putchar.c
#	$(CC) -c -o $@ $(CFLAGS) $^
#ft_swap.o : ft_swap.c
#	$(CC) -c -o $@ $(CFLAGS) $^
#ft_putstr.o : ft_putstr.c
#	$(CC) -c -o $@ $(CFLAGS) $^
#ft_strlen.o : ft_strlen.c
#	$(CC) -c -o $@ $(CFLAGS) $^
#ft_strcmp.o : ft_strcmp.c
#	$(CC) -c -o $@ $(CFLAGS) $^

.PHONY : clean

clean :
	rm -f $(OBJS)
fclean :
	rm -f $(OBJS) $(TARGET)
re :
	make fclean
	make all
