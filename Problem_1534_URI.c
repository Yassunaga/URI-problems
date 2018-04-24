#include<stdlib.h>
#include<stdio.h>

int main()
{
    int n, i, j;
    int mat[70][70];

    while(scanf("%d", &n)!=EOF && n>=3 && n<70)
    {
        for(i=0; i<n; i++)
        {
            for(j=0;j<n;j++)
            {
                if(i+j==n-1)
                {
                    mat[i][j] = 2;
                }
                else
                {
                    if(i==j)
                    {
                        mat[i][j] = 1;
                    }
                    else
                    {
                        mat[i][j] = 3;
                    }
                }
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
    }
}

