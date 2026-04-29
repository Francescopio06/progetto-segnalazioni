CC = gcc
CFLAGS = -Wall -Wextra

OBJ = main.o segnalazione.o BST.o gestione.o

main.out: ${OBJ}
	${CC} ${OBJ} -o main.out


main.o: main.c
	${CC} ${CFLAGS} -c main.c

segnalazione.o: segnalazione.c
	${CC} ${CFLAGS} -c segnalazione.c

BST.o: BST.c
	${CC} ${CFLAGS} -c BST.c

gestione.o: gestione.c
	${CC} ${CFLAGS} -c gestione.c

clean: 
	rm -f *.o main.out