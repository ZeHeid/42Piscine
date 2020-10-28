CC = gcc
CFlAGS = -I $(HEADIR) -Wall -Werror -Wextra
EXEC = rush-02
SRC = ${wildcard srcs/*.c}
OBJ = ${SRC:.c=.o}
HEADIR = includes


all: ${EXEC}

.c.o:
	${CC} -c $< -o ${<:.c=.o} ${CFLAGS}

${EXEC}: ${OBJ}
	${CC} $^ -o  ${EXEC} ${CFLAGS}

clean:
	rm ${OBJ}

fclean: clean
	rm ${EXEC}

