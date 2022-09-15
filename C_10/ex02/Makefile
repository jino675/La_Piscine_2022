OBJS = main.o ft_strlen.o ft_atoi.o print.o
HDRS = ft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = ft_tail


all : $(TARGET) $(HDRS)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^

%.o : %.c
	$(CC) -c -o $@ $(CFLAGS) $<


.PHONY : clean

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
