t_OBJS = main.o first_line.o print_ans.o rest_lines.o
OBJS = $(addprefix srcs/, $(t_OBJS))
HDRS = bsq.h

INCLUDE = includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = bsq

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)

%.o : %.c
	$(CC) -c -o $@ -I $(INCLUDE) $(CFLAGS) $<

.PHONY : clean fclean re all
	
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
