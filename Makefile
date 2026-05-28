CC = gcc

CFLAGS = -std=c89 -Wall -Wextra -pedantic \
		 -I./Modulo_Segnalazione \
		 -I./Modulo_BST \
		 -I./Modulo_Gestione \
		 -I./Modulo_Tests/include \
		 -I./Modulo_Tests/src

OBJDIR = obj

MAIN_OBJ = $(OBJDIR)/main.o \
		   $(OBJDIR)/segnalazione.o \
		   $(OBJDIR)/BST.o \
		   $(OBJDIR)/gestione.o


TEST_OBJ = $(OBJDIR)/main_test.o \
		   $(OBJDIR)/segnalazione.o \
		   $(OBJDIR)/BST.o \
		   $(OBJDIR)/gestione.o \
		   $(OBJDIR)/inserimento.o \
		   $(OBJDIR)/ricerca.o \
		   $(OBJDIR)/aggiornamento.o \
		   $(OBJDIR)/urgenza.o \
		   $(OBJDIR)/filtra.o \
		   $(OBJDIR)/report.o \
		   $(OBJDIR)/cancellazione.o \
		   $(OBJDIR)/supporto.o


all: main.out main_test.out


run: main.out
	./main.out


run-test: main_test.out
	./main_test.out


main.out: $(MAIN_OBJ)
	$(CC) $^ -o $@


main_test.out: $(TEST_OBJ)
	$(CC) $^ -o $@


$(OBJDIR)/main.o: main.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/main_test.o: main_test.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/segnalazione.o: Modulo_Segnalazione/segnalazione.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/BST.o: Modulo_BST/BST.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/gestione.o: Modulo_Gestione/gestione.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/inserimento.o: Modulo_Tests/src/inserimento.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/ricerca.o: Modulo_Tests/src/ricerca.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/aggiornamento.o: Modulo_Tests/src/aggiornamento.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/urgenza.o: Modulo_Tests/src/urgenza.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/filtra.o: Modulo_Tests/src/filtra.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/report.o: Modulo_Tests/src/report.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/cancellazione.o: Modulo_Tests/src/cancellazione.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR)/supporto.o: Modulo_Tests/src/supporto.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJDIR) main.out main_test.out