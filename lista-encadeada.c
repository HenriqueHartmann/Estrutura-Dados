#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

struct lista {
	int info;
	struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializa (void)
{
	return NULL;
}

Lista* insere (Lista* l, long i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void imprime (Lista* l)
{
	Lista* p;
	for (p=l; p != NULL; p = p->prox)
	{
		printf("info = %d\n", p->info);
	}
}

int vazia (Lista* l)
{
	if (l == NULL)
	{
		printf("lista vazia\n");
		return 1;
	}
	else 
	{
		printf("lista nao esta vazia\n");
		return 0;
	}
}

Lista* busca (Lista* l, long v)
{
	Lista* p;
	for (p=l; p!=NULL; p=p->prox)
	{
		if (p->info == v)
		{
			printf("v: %d, foi encontrado \n", v);
			printf("prox: %d\n", p->prox);
			return p;
		}
	}
	printf("v: %d, nao foi encontrado \n", v);
	return NULL;
}

Lista* retira (Lista* l, long v)
{
	Lista* ant = NULL;
	Lista* p = l;
	
	while (p != NULL && p->info != v)
	{
		ant = p;
		p = p->prox;
	}
	
	if (p == NULL)
	{
		return l;
	}
	
	if (ant == NULL)
	{
		l = p->prox;
	}
	else
	{
		ant->prox = p->prox;
	}
	free(p);
	return l;
}

void libera (Lista* l)
{
	Lista* p = l;
	Lista* t = NULL;
	while (p != NULL)
	{
		t = p->prox;
		free(p);
		p = t;
	}
}

Lista* inserirOrdenadamente (Lista* l, long i)
{	
	if (l == NULL) {
		return insere(l, i);
	}
	else
	{	
		Lista* ant = NULL;
		Lista* p = l;
		while (p != NULL && p->info < i)
		{
			ant = p;
			p = p->prox;
		}
		if (ant == NULL)
		{
			return insere(l, i);
		}
		else
		{
			Lista* novo = (Lista*) malloc(sizeof(Lista));
			novo->info = i;
			
			novo->prox = ant->prox;
			ant->prox = novo;	
		}
		
		return l;
	}
}

int main (void)
{
	Lista* l;
	l = inicializa();
//	vazia(l);
//	l = insere(l, 23);
//	l = insere(l, 45);
//	l = insere(l, 50);
//	vazia(l);
//	l = retira(l, 50);
//	imprime(l);
//	busca(l, 23);
//	busca(l, 45);
//	busca(l, 50);
//	libera(l);
	l = inserirOrdenadamente(l, 30);
	l = inserirOrdenadamente(l, 25);
	l = inserirOrdenadamente(l, 26);
	l = inserirOrdenadamente(l, 20);
	l = inserirOrdenadamente(l, 90);
	imprime(l);
	
	return 0;
}

