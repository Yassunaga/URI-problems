#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista
{
	int qtd_par;
	int qtd_impar;
	struct par *i_par;
	struct impar *i_impar;
}lista;

typedef struct par
{
	int num;
	struct par *prox;
}par;

typedef struct impar
{
	int num;
	struct impar *prox;
}impar;

void incluir_par(lista * l, int num);
void incluir_impar(lista * l, int num);
void remover_par(lista * l);
void remover_impar(lista *l);
int mostrar_par(lista* l);
int mostrar_impar(lista* l);
lista * aloca_lista();
par * aloca_par();
impar * aloca_impar();

int main()
{	
	int i;
	int num;
	lista * l1;
	l1 = aloca_lista();
	int cont_par=0;
	int cont_impar=0;
	
	for(i=0;i<15;i++)
	{
		scanf("%d", &num);
		if(num % 2 ==0)
		{
			incluir_par(l1, num);
			cont_par++;
			if(cont_par==5)
			{
				mostrar_par(l1);
				remover_par(l1);
				cont_par=0;
			}
		}
		else
		{
			incluir_impar(l1,num);
			cont_impar++;
			if(cont_impar==5)
			{
				mostrar_impar(l1);
				remover_impar(l1);
				cont_impar=0;
			}
		}
	}
	mostrar_impar(l1);
	mostrar_par(l1);
	return 0;
}

par * aloca_par()
{
	par * novo;
	novo = (par*)malloc(sizeof(par));
	novo->num = 0;
	novo->prox = NULL;
	return novo;
}

impar * aloca_impar()
{
	impar * novo;
	novo = (impar*)malloc(sizeof(impar));
	novo->num = 0;
	novo->prox = NULL;
	return novo;
}

lista * aloca_lista()
{
	lista * novo;
	novo = (lista*)malloc(sizeof(lista));
	novo->qtd_par = 0;
	novo->qtd_impar=0;
	novo->i_par=NULL;
	novo->i_impar=NULL;
	return novo;
}

void incluir_par(lista * l, int num)
{
	par *novo;
	par * aux;
	novo = aloca_par();
	novo->num = num;
	if(l->i_par==NULL)
	{
		l->i_par = novo;
	}
	else
	{
		aux=l->i_par;
		while(aux->prox!=NULL)
		{
			aux = aux->prox;
		}
		aux->prox= novo;
	}
}

void incluir_impar(lista * l, int num)
{
	impar *novo;
	impar * aux;
	novo = aloca_impar();
	novo->num = num;
	if(l->i_impar==NULL)
	{
		l->i_impar = novo;
	}
	else
	{
		aux=l->i_impar;
		while(aux->prox!=NULL)
		{
			aux = aux->prox;
		}
		aux->prox= novo;
	}
}

int mostrar_par(lista * l)
{
	par * aux;
	int i;
	if(l->i_par==NULL)
	{
		return 0;
	}
	else
	{
		aux = l->i_par;
		i=0;
		while(aux!=NULL)
		{
			printf("par[%d] = %d\n",i, aux->num);
			i++;
			aux = aux->prox;
		}
	}
}

int mostrar_impar(lista * l)
{
	impar * aux;
	int i;
	if(l->i_impar==NULL)
	{
		return 0;
	}
	else
	{
		aux = l->i_impar;
		i=0;
		while(aux!=NULL)
		{
			printf("impar[%d] = %d\n",i, aux->num);
			i++;
			aux = aux->prox;
		}
	}
}

void remover_par(lista *l)
{
	par * aux;
	par * ant;
	ant = NULL;
	aux = l->i_par;
	while(aux->prox!=NULL)
	{
		ant = aux;
		aux = aux->prox;
		free(ant);
		if(aux->prox==NULL)
		{
			free(aux);
		}
	}
	l->i_par=NULL;
}

void remover_impar(lista *l)
{
	impar * aux;
	impar * ant;
	ant = NULL;
	aux = l->i_impar;
	while(aux->prox!=NULL)
	{
		ant = aux;
		aux = aux->prox;
		free(ant);
		if(aux->prox==NULL)
		{
			free(aux);
		}
	}
	l->i_impar=NULL;
}

