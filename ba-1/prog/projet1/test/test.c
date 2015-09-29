#include <stdlib.h>
#include <stdio.h>
static void func1(int * p);
static void func2(int * p);
int main(int argc, const char * argv[])
{
	int nbL = 3;
	int nbC = 3;
	int Tableau[3][3] = {{0,0,0},
							 {3,4,5},
							 {6,7,8}};
	
	int *p = (int*)Tableau;
	func1(p);
	printf("%d\n\n", *p);
}

static void func1(int * p)
{
	func2(p);
return;
}

static void func2(int * p)
{
	*p = *p + 1;
}

