#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#ifdef WIN32
	#include <windows.h>
#else//LINUX
	#include <sys/ioctl.h>
#endif

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

struct TSIZE
{
	int width;
	int height;
	int sapin_height;
	int sapin_width;
	int sky_height;
};

static void clear();
static int tWidth();
static int tHeight();
static void clearColor();
static void setColor(int foreground, int background, int style);
static void fillTerminal(int background, struct TSIZE);
static void sapin(struct TSIZE*);

int main()
{
	clear();
	struct TSIZE terminal;
	terminal.width = tWidth();
	terminal.height = tHeight();
	printf("HEIGHT : %d\tWIDTH : %d\n", terminal.height, terminal.width);	
	sapin(&terminal);

	char arrayF[tWidth()][tHeight()];
	char arrayB[tWidth()][tHeight()];

	fillTerminal(F_BLUE, terminal);

	setColor(F_BLUE, B_BLACK, BOLD);
	clearColor();
	getchar();
}

static void fillTerminal(int background, struct TSIZE t)
{
	int i, j;
	setColor(F_BLACK, background, BOLD);
	for(i = 0; i < t.height; i++)
		for(j = 0; j < t.width; j++)
			printf("%c", 240);
}

static void sapin(struct TSIZE *t)
{
	t->sapin_height = t->height * 2 / 3;
	int tmp = 1, i;
	
	for(i = 1; tmp < t->sapin_height; i++)
	{
		tmp = i*(i+1);
		tmp /= 2;
	}
	tmp =
	tmp =  
	t->sapin_height = tmp;
	printf("HEIGHT : %d\t WIDTH : %d\n", t->sapin_height, tmp);
}

static void setColor(int foreground, int background, int style)
{
	printf("%c[%d;%d;%dm", MAGIC, style, foreground, background);
}

static int tWidth()
{
#ifdef WIN32
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Right - csbi.srWindow.Left + 1;
#else
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
#endif
}

static int tHeight()
{
#ifdef WIN32
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_row;
#endif
}

static void clearColor()
{
	printf("%c[%dm", 0x1B, 0);
}

static void clear()
{
	printf("%s", "\e[1;1H\e[2J");
}
