#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

struct listaDup {
	int info;
	struct listaDup* ant;
	struct listaDup* prox;
};

typedef struct listaDup ListaDupla;

// Protótipo das funções
ListaDupla* insere (ListaDupla* l, int v);
void imprime (ListaDupla* l);
ListaDupla* busca (ListaDupla* l, int v);
void libera (ListaDupla* l);
ListaDupla* separa (ListaDupla* lista, int n);

// Função Main
int main (void)
{
	ListaDupla* l = NULL;
	l = insere(l, 1);
	l = insere(l, 2);
	l = insere(l, 3);
	l = insere(l, 4);
	l = insere(l, 5);
	l = insere(l, 6);
	imprime(l);
	printf("\n");

	ListaDupla* t = NULL;
	t = separa(l, 5);
	printf("Lista 1: \n");
	imprime(l);
	printf("Lista 2: \n");
	imprime(t);
	
	libera(l);
	libera(t);
	
	return 0;
}

// Desenvolvimento das funções
ListaDupla* insere (ListaDupla* l, int v)
{
	ListaDupla* novo = (ListaDupla*) malloc(sizeof(ListaDupla));
	novo->info = v;
	novo->prox = l;
	novo->ant = NULL;
	
	if (l != NULL)
	{
		l->ant = novo;
	}
	return novo;
}

void imprime (ListaDupla* l)
{
	ListaDupla* p = l;
	for (p; p != NULL; p = p->prox)
	{
		printf("%d | info: %d | prox: %d | ant: %d \n", p, p->info, p->prox, p->ant);
	}
}

ListaDupla* busca (ListaDupla* l, int v)
{
	ListaDupla* p;
	for (p = l; p != NULL; p = p->prox)
	{
		if (p->info == v)
		{
			return p;
		}
	}
	return NULL;
}

void libera (ListaDupla* l)
{
	ListaDupla* p = l;
	ListaDupla* t = NULL;
	while (p != NULL)
	{
		t = p->prox;
		free(p);
		p = t;
	}
}

ListaDupla* separa (ListaDupla* l, int n)
{
	ListaDupla* p = busca(l, n);
	if (p != NULL)
	{
		ListaDupla* t = p->prox;
		p->prox->ant = NULL;
		p->prox = NULL;
		return 	t;
	}
	return p;
}

