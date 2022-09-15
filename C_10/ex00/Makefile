OBJS = main.o


CC = gcc
CFLAGS = -Wall -Wextra -Werror


TARGET = ft_display_file


all : $(TARGET)


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
