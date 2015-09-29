#include <stdlib.h>
#include <stdio.h>
static void func1(int *p);
int main(int argc, const char * argv[])
{
	int nbL = 3;
	int nbC = 3;
	int Tableau[3][3] = {{0,1,2},
			 {3,4,5},
			 {6,7,8}};
	
	int *p = (int*)Tableau;
	func1(p);
}

static void func1(int * p)
{
	int zoom = 100;
	int nbL = 3;
	int nbC = 3;
	int i=0,j=0,k=0,l=0, depass=0;

	for(i = 0; i < nbL; i++)//parcours le tableau de base ligine
		for(k = 0; k < zoom; k++)//va imprimer zoom fois la ligne
		{
			for(j = 0; j < nbC; j++)//parcours le tableau de base col
				for(l = 0; l < zoom; l++)//copie zoom fois la col
				{
					if(depass==70)
					{
						printf("\n");
						depass=0;
					}
					depass++;
					printf("%d", *(p + (i*nbL)+j));
				}
			printf("\n");
		}
}
