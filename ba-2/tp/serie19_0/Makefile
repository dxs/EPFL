# Compilateur a utiliser :
##########################

CC     = gcc

# Options de compilation : (-g = pour deverminer)
#################################################

CFLAGS = -g

# Repertoire include :
#########################

#INCLUDE_DIR   = /usr/local/include/

# Librairies a utiliser :
#########################

LIBS   = -lstdc++ -lglut -lGL -lGLU -lm -L/usr/X11R6/lib -lX11 -lXext -lXmu -lXi

# Liste de fichiers source (.c) a compiler :
############################################

CFILES = serie19_0.cpp

# Liste de modules objets (generee a partir de CFILES) :
########################################################

OFILES = $(CFILES:.cpp=.o)

# Nom du fichier executable :
#############################

CIBLE  = serie19_0.x

# edition de liens (rassembler tous les objets -> executable)
#############################################################

$(CIBLE): $(OFILES)
	$(CC) $(OFILES) ${LIBS} -o $(CIBLE)


# compilation separee (production du module objet seulement)

serie19_0.o: serie19_0.cpp
	$(CC) -c serie19_0.cpp $(CFLAGS)




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
