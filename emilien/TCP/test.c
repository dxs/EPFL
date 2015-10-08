#include <stdlib.h>
#include <stdio.h>

int func(int n);

int main(void)
{	
	int n = 5;
	n = func(n);
	printf("%d", n);
}

int func(int n)
{
	if(n == 0)
		return 0;
	return 2*n-1 + func(n-1);
}
