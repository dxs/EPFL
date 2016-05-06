#include <stdio.h>
#include <stdlib.h>

void function_causing_seg_fault(void)
{
	const int numberOfIntegers = 100000;
	int* p = (int*) malloc(numberOfIntegers); 
	
	int i;
	for(i = 0; i < numberOfIntegers; ++i)
		p[i] = i;
		
	free(p);
}

int main(void)
{
	function_causing_seg_fault();	
	return EXIT_SUCCESS;
}
