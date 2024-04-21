CC = gcc
CFLAGS = -Wall -std=c11
DEPS = ajout.h main-header.h afficher.h rechercher.h supprimer.h trier.h menu.h modifier.h fichiers.h
OBJ = main.o ajout.o afficher.o rechercher.o supprimer.o trier.o menu.o modifier.o fichiers.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gestion_etudiants: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o gestion_etudiants