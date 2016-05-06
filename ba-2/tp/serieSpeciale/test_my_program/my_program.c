#include <stdio.h>

int main(void)
{
        int no1, no2;
        
        if(scanf("%d%d", &no1, &no2) == 2)
                printf("%d\n", no1+no2);
        else
                printf("Illegal input!\n");
        
        return 0;
}
