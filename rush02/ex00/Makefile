CCFLAGS = gcc -Wall -Wextra -Wextra

TARGET = rush-02
SRCDIR = srcs
HDRDIR = header
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CCFLAGS) -c $< -o  $@ -I $(HDRDIR)

$(TARGET): $(OBJS)
	$(CCFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
