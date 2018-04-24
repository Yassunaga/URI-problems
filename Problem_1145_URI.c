#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x, y, i, j=1;

    scanf("%d %d", &x, &y);

    for(i=1;i<=y;i++)
    {
        if(i%x == 0)
        {
            printf("%d", i);
        }
        else
        {
            printf("%d ", i);
        }

        if(i==j*x)
        {
            printf("\n");
            j++;
        }
    }
    return 0;
}

