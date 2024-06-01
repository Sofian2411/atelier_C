#Makefile
CC = gcc
CFALGS = -std=c99 -Werror
LDLIBS = -lcriterion

SRC = linked_list.c test.c
OBJ = ${SRC:.c=.o}

ll: linked_list.o main.o
	${CC} ${CFALGS} -o $@ $^

%.o: %.c
	${CC} ${CFALGS} -c $< -o $@

test: ${OBJ}
	${CC} ${CFLAGS} ${LDLIBS} ${OBJ} -o $@

check: test 
	./test

.PHONY: clean, check, test

clean:
	${RM} ${DEP} ${OBJ} ll test main.o
