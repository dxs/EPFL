# Compilateur a utiliser :
##########################

CC     = gcc

# Options de compilation : (-g = pour deverminer)
#################################################

CFLAGS = -g


# Librairies a utiliser :
#########################

LIBS   = -lstdc++ -lglut -lGL -lGLU -lglui -L/usr/X11R6/lib -lX11 -lXext -lXmu -lXi -lm

# Liste de fichiers source (.c) a compiler :
############################################

CFILES = serie18_0.cpp

# Liste de modules objets (generee a partir de CFILES) :
# Les fichiers objets (.o) ont le même nom que les fichiers source (.c)
# Seulement le suffixe change.
########################################################

OFILES = $(CFILES:.c=.o)

# Nom du fichier executable :
#############################

CIBLE  = serie18_0.x

# edition de liens (rassembler tous les objets -> executable)
#############################################################

cine.x: $(OFILES) 
	$(CC) $(OFILES) ${LIBS} -o $(CIBLE)


# compilation separee (production du module objet seulement)


cine.o: $(GLUI_OBJS) serie18_0.cpp 
	$(CC) -c serie18_0.cpp $(CFLAGS)


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
	@/bin/rm -f *.o *.x

#
# -- Regles de dependances generees par "make depend"
#####################################################
# DO NOT DELETE THIS LINE
chaine.o: chaine.c chaine.h graphic.h
graphic.o: graphic.c graphic.h
cine.o: cine.cpp graphic.h chaine.h
