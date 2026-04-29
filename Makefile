CC = gcc
CFLAGS = -Wall -Wextra -I./Modulo_Segnalazione -I./Modulo_BST -I./Modulo_Gestione
OBJDIR = obj
TARGET = main.out

OBJ = ${OBJDIR}/main.o \
	${OBJDIR}/segnalazione.o \
	${OBJDIR}/BST.o \
	${OBJDIR}/gestione.o

${TARGET}: ${OBJ}
	${CC} ${OBJ} -o ${TARGET}

${OBJDIR}/main.o: main.c
	@mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}/segnalazione.o: Modulo_Segnalazione/segnalazione.c
	@mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}/BST.o: Modulo_BST/BST.c
	@mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}/gestione.o: Modulo_Gestione/gestione.c
	@mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJDIR} main.out