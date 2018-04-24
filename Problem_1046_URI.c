#include<stdio.h>
#include<stdlib.h>

int main()
{
    int ini, fim, result;

    scanf("%d %d", &ini, &fim);

    if(ini>fim)
    {
        result = (24 - ini) + fim;
    }

    if(ini == fim)
    {
        result = 24;
    }

    if(ini<fim)
    {
        result = (fim-ini);
    }

    printf("O JOGO DUROU %d HORA(S)\n", result);

    return 0;
}

