#include <stdlib.h>
#include <stdio.h>

// evaluates (x^2 + y^2) / (x + y)
float calculateExpression(int x, int y)
{
	int xx = x * x;
	int yy = y * y;
	int numerator = xx + yy;
	int denominator = x + y;
	float result = numerator / denominator;
	return result;
}


int main()
{
	int x, y;
	printf("Please enter 2 integers: \n");
	scanf("%d %d", &x, &y);
	float result = calculateExpression(x, y);
	printf("Result of the expression is %f\n", result);
	return EXIT_SUCCESS;
}
