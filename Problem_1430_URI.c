#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    double calcular(char c);
    char str[1000001];
    int i, l;
    double cont1;
    int cont2;
    while(gets(str) && str[0] != '*')
    {
        cont2=cont1=0;
        l=strlen(str);
        for(i=0;i<l;++i)
        {
            if(str[i]=='/')
            {
                if(cont1==1.00)
                {
                    cont2++;
                }
                cont1=0;
            }
            else
            {
                cont1 += calcular(str[i]);
            }
        }
    printf("%d\n", cont2);
    }
    return 0;
}

double calcular(char c)
{
    if(c=='W')
        return 1.0;
    else if(c=='H')
        return 0.5;
    else if(c=='Q')
        return 0.25;
    else if(c=='E')
        return 0.125;
    else if(c=='S')
        return 0.0625;
    else if(c=='T')
        return 0.03125;
    else if(c=='X')
        return 0.015625;
}

