#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allocInt(int size)
{
	return (int*) malloc(sizeof(int) * size);
}

void fillRandomly(int* p, int size)
{
	int i;
	for(i = 0; i < size; ++i)
		p[i] = rand() % size;
}

void print(int* p, int size)
{
	int i;
	for(i = 0; i <= size; ++i)
		printf("%d ", p[i]);
	printf("\n");
}

int main(void)
{
	srand(time(NULL));
	
	int* p = allocInt(100);
	fillRandomly(p, 100);
	print(p, 100);
	
	free(p);
	
	return EXIT_SUCCESS;
}
