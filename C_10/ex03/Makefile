t_OBJS = main.o ft_strlen.o ft_strcmp.o print.o input.o
OBJS = $(addprefix srcs/, $(t_OBJS))
t_HDRS = ft.h
HDRS = $(addprefix includes/, $(t_HDRS))

INCLUDES = includes

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

TARGET = ft_hexdump


all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^

%.o : %.c $(HDRS)
	$(CC) -c -o $@ -I $(INCLUDES) $(CFLAGS) $<


.PHONY : clean

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
