CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c src/parser.c src/executor.c src/redirection.c
OBJ = $(SRC:.c=.o)
INCLUDE = -Iinclude
TARGET = minishell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all
