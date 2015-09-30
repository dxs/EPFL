#include <stdlib.h>
#include <stdio.h>

struct valeurBase
{
	int x;
	int y;
};

int main (int argc, const char * argv[])
{
	struct valeurBase val;
	val.x = 1;
	val.y = 2;
	struct valeurBase * pVal = &val;
	printf("%d", pVal->x);
}
