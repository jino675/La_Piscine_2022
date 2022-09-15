OBJS = main.o ft_atoi.o ft_putnbr.o operation.o
SRCS = $(OBJS: .o=.c)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = do-op

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^

%.o : %.c
	$(CC) -c -o $@ $(CFLAGS) $<

.PHONY : clean

clean :
	rm -f $(OBJS)
fclean :
	rm -f $(OBJS) $(TARGET)
re :
	make fclean
	make all
