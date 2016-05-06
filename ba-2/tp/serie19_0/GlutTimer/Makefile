CC=gcc

LIBS   = -lstdc++ -lglut -lGL -lGLU -lm -L/usr/X11R6/lib -lX11 -lXext -lXmu -lXi

all: chronometer

chronometer: chronometer.o
	$(CC) chronometer.o -o chronometer ${LIBS}

chronometer.o: chronometer.c
	$(CC) -c chronometer.c

clean:
	rm -rf *o chronometer

