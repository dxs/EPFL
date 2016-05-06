# Compilateur a utiliser :
##########################

CC     = gcc

# Options de compilation : (-g = pour deverminer)
#################################################

CFLAGS = -g


# Librairies a utiliser :
# LIBS: toutes les librairies qu'il faut intégrer
#########################

LIBS   = -lglut -lGL -lGLU -lm -lglui -L/usr/X11R6/lib -lX11 -lXext -lXmu -lXi -lstdc++

# Liste de fichiers source (.c) a compiler :
############################################

CFILES = chaine.c graphic.c cine.cpp

# Liste de modules objets (generee a partir de CFILES) :
# Les fichiers objets (.o) ont le même nom que les fichiers source (.c)
# Seulement le suffixe change.
########################################################

OFILES = $(CFILES:.c=.o)

# Nom du fichier executable :
#############################

CIBLE  = cine.x

# edition de liens (rassembler tous les objets -> executable)
#############################################################

cine.x: $(OFILES) 
	$(CC) $(OFILES) -o $(CIBLE) ${LIBS}


# compilation separee (production du module objet seulement)

graphic.o: graphic.c
	$(CC) -c graphic.c $(CFLAGS)

cine.o: $(GLUI_OBJS) cine.cpp 
	$(CC) -c cine.cpp $(CFLAGS)

chaine.o: chaine.c
	$(CC) -c chaine.c $(CFLAGS)



# Definitions de cibles particulieres :
#
# "make depend" : genere la liste des dependances
# "make clean"  : efface les fichiers .o et .x
#################################################

depend:
	@echo " *** MISE A JOUR DES DEPENDANCES ***"
	@(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	  $(CC) -MM $(CFLAGS) $(CFILES) | \
	  egrep -v "/usr/include" \
	 ) >Makefile.new
	@mv Makefile.new Makefile

clean:
	@echo " *** EFFACE MODULES OBJET ET EXECUTABLE ***"
	@/bin/rm -f *.o cine.x

#
# -- Regles de dependances generees par "make depend"
#####################################################
# DO NOT DELETE THIS LINE
chaine.o: chaine.c chaine.h graphic.h
graphic.o: graphic.c graphic.h
cine.o: cine.cpp graphic.h chaine.h
