#Makefile
CC = gcc
CFALGS = -std=c99 -Werror -fsanitize=address -g

SRC = hello_world.c main_with_args.c size_of_stuff.c there_are_no_strings.c structs.o
OBJ = ${SRC:.c=.o}

#h: ${OBJ}

all: ${OBJ}
	${CC} ${CFALGS} -o hello hello_world.o
	${CC} ${CFALGS} -o args main_with_args.o
	${CC} ${CFALGS} -o size size_of_stuff.o
	${CC} ${CFALGS} -o strings there_are_no_strings.o
	${CC} ${CFALGS} -o structs structs.o

hello: hello_world.o
	${CC} ${CFALGS} -o $@ $^

args: main_with_args.o
	${CC} ${CFALGS} -o $@ $^

size: size_of_stuff.o
	${CC} ${CFALGS} -o $@ $^

strings: there_are_no_strings.o
	${CC} ${CFALGS} -o $@ $^

structs: structs.o
	${CC} ${CFLAGS} -o $@ $^

%.o: %.c
	${CC} ${CFALGS} -c $< -o $@

.PHONY: clean

clean:
	${RM} ${OBJ} hello args size strings structs
