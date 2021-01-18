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

typedef struct listaDup ListaDUPLA;

ListaDUPLA* inicializa(void)
{
	return NULL;
}

ListaDUPLA* insere (ListaDUPLA* l, int v)
{
	ListaDUPLA* novo = (ListaDUPLA*) malloc(sizeof(ListaDUPLA));
	novo->info = v;
	novo->prox = l;
	novo->ant = NULL;
	
	if (l != NULL)
	{
		l->ant = novo;
	}
	
	return novo;
}

ListaDUPLA* busca (ListaDUPLA* l, int v)
{
	ListaDUPLA* p;
	for (p = l; p != NULL; p = p->prox)
	{
		if (p->info == v)
		{
			return p;
		}
	}
	return NULL;
}

void imprimeBusca (ListaDUPLA* r)
{
	if (r == NULL)
	{
		printf("nao foi encontrado \n");
	}
	else
	{
		printf("info: %d ant: %d prox: %d \n", r->info, r->ant, r->prox);	
	}
}

ListaDUPLA* retira (ListaDUPLA* l, int v)
{
	ListaDUPLA* p = busca(l, v);
	
	if (p == NULL)
	{
		return l;
	}
	
	if (l == p)
	{
		l = p->prox;
	}
	else
	{
		p->ant->prox = p->prox;
	}
	
	if (p->prox != NULL)
	{
		p->prox->ant = p->ant;
	}
	
	free(p);
	
	return l;
}

void imprime (ListaDUPLA* l)
{
	ListaDUPLA* p = l;
	for (p; p != NULL; p = p->prox)
	{
		printf("info: %d ant: %d prox: %d \n", p->info, p->ant, p->prox);
	}
}

int vazia (ListaDUPLA* l)
{
	return (l == NULL);
}

void imprimeVazia(int r)
{
	if (r == 0)
	{
		printf("lista nao esta vazia\n");	
	}
	else
	{
		printf("lista vazia\n");
	}
}

ListaDUPLA* insereOrdenado (ListaDUPLA* l, int v)
{
	if (l == NULL)
	{
		l = insere(l, v);
	}
	else
	{
		ListaDUPLA* ant = NULL;
		ListaDUPLA* p = l;
		while (p != NULL && p->info < v)
		{
			ant = p;
			p = p->prox;
		}
		if (ant == NULL)
		{
			return insere(l, v);
		}
		else
		{	
			ListaDUPLA* novo = (ListaDUPLA*) malloc(sizeof(ListaDUPLA));
			novo->info = v;
			novo->prox = ant->prox;
			novo->ant = ant;
			
			if (p != NULL)
			{
				p->ant = novo;
			}
			
			ant->prox = novo;
		}
		
		return l;
	}
}

void libera (ListaDUPLA* l)
{
	ListaDUPLA* p = l;
	ListaDUPLA* t = NULL;
	while (p != NULL)
	{
		t = p->prox;
		free(p);
		p = t;
	}
}

ListaDUPLA* buscaUltimo (ListaDUPLA* l)
{
	ListaDUPLA* u = NULL;
	ListaDUPLA* p = l;
	
	for (p; p != NULL; p = p->prox)
	{
		u = p;
	}
	return u;
}

void imprimeInverso (ListaDUPLA* l)
{
	ListaDUPLA* u = buscaUltimo(l);
	ListaDUPLA* p = l;
	
	for (p=u; p != NULL; p = p->ant)
	{
		printf("info: %d ant: %d prox: %d \n", p->info, p->ant, p->prox);
	}
}

int main (void)
{
	ListaDUPLA *l;
	l = inicializa();
//	imprimeVazia(vazia(l));
//	l = insere(l, 22);
//	imprimeVazia(vazia(l));
//	l = insere(l, 25);
//	l = insere(l, 28);
//	imprimeBusca(busca(l, 22));
//	l = retira(l, 22);
//	imprimeBusca(busca(l, 22));
//	imprime(l);
	l = insereOrdenado(l, 23);
	l = insereOrdenado(l, 24);
	l = insereOrdenado(l, 25);
	l = insereOrdenado(l, 27);
	l = insereOrdenado(l, 26);
//	imprime(l);
	imprimeInverso(l);
//	libera(l);
	
	return 0;	
}

