# Definitions de macros

CC     = gcc
CFLAGS = -Wall
CFILES = calendrier.c difference.c main.c
OFILES = calendrier.o difference.o main.o

# Definition de la premiere regle

programme.x: $(OFILES)
	$(CC) $(OFILES) -lm -o programme.x

# Definitions de cibles particulieres

depend:
	@echo " *** MISE A JOUR DES DEPENDANCES ***"
	@(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	  $(CC) -MM $(CFLAGS) $(CFILES) | \
	  egrep -v "/usr/include" \
	 ) >Makefile.new
	@mv Makefile.new Makefile

clean:
	@echo " *** EFFACE MODULES OBJET ET EXECUTABLE ***"
	@/bin/rm -f *.o *.x *.c~ *.h~

#
# -- Regles de dependances generees automatiquement
#
# DO NOT DELETE THIS LINE
calendrier.o: calendrier.c calendrier.h
difference.o: difference.c calendrier.h difference.h
main.o: main.c calendrier.h difference.h
