#include <stdlib.h>
#include <stdio.h>

#define MAGIC 	0x1B

//ATTRIBUTE
#define OFF 	0
#define BOLD 	1
#define UNDERSC	4
#define BLINK	5
#define REVERSE	7
#define CONCEAL	8

//FOREGROUND COLOR
#define F_BLACK		30
#define F_RED		31
#define F_GREEN		32
#define F_YELLOW	33
#define F_BLUE 		34
#define F_MAGENTA	35
#define F_CYAN 		36
#define F_WHITE 	37

//BACKGROUND COLOR
#define B_BLACK		40
#define B_RED		41
#define B_GREEN		42
#define B_YELLOW 	43
#define B_BLUE 		44
#define B_MAGENTA 	45
#define B_CYAN 		46
#define B_WHITE 	47

static void clear();

int main()
{
	printf("%c[%d;%d;%dmHello Sven\n", MAGIC, BOLD, WHAT, B_BLACK);
	clear();
	getchar();
}

static void clear()
{
	printf("%c[%dm", 0x1B, 0);
}
