CC=gcc
CFLAGS=-I. -Wall -Wextra -Werror

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

my_mastermind: my_mastermind.o
	$(CC) -o my_mastermind my_mastermind.o