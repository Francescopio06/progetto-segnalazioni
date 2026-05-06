CC = gcc

CFLAGS = -Wall -Wextra \
		 -I./Modulo_Segnalazione \
		 -I./Modulo_BST \
		 -I./Modulo_Gestione

OBJDIR = obj


MAIN_OBJ = $(OBJDIR)/main.o \
		   $(OBJDIR)/segnalazione.o \
		   $(OBJDIR)/BST.o \
		   $(OBJDIR)/gestione.o


TEST_OBJ = $(OBJDIR)/main_test.o \
		   $(OBJDIR)/segnalazione.o \
		   $(OBJDIR)/BST.o \
		   $(OBJDIR)/gestione.o


all: main.out main_test.out


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


clean:
	rm -rf $(OBJDIR) main.out main_test.out