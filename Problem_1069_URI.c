#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int topo=0;
int pilha[1001];
void push(int x);
int pop();
int cont=0;

int main()
{
    int n, i;
    char nome[1000];
    scanf("%d", &n);

    while(n--)
    {
        fflush(stdin);
        gets(nome);
        for(i=0; i<strlen(nome); i++)
        {
            if(nome[i] == '<')
            {
                push(1);
            }
            else
            {
                if(nome[i] == '>')
                {
                    if(pop())
                    {
                        cont++;
                    }
                }
            }
        }
        for(i=0; i<strlen(nome); i++)
        {
            nome[i]=0;
            pilha[i]=0;
        }

        printf("%d\n", cont);
        topo=0;
        cont=0;
    }
}

void push(int x)
{
    topo++;
    pilha[topo] = x;
}

int pop()
{
    if(topo==0)
    {
        return 0;
    }
    else
    {
        pilha[topo] = 0;
        topo--;
        return 1;
    }
}
