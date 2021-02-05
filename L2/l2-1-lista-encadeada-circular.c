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

// Protótipo das funções
Lista* insere (Lista* l, int v);
void imprime (Lista* l);
Lista* busca (Lista* l, int v);
Lista* retira (Lista* l, int v);
void libera (Lista* l);

// Função Main
int main (void)
{
	Lista* l = NULL;
	l = insere(l, 1);
	l = insere(l, 2);
	l = insere(l, 3);
	l = insere(l, 4);
	l = insere(l, 5);
	imprime(l);
	l = retira(l, 1);
	l = retira(l, 5);
	printf("\n");
	imprime(l);
	printf("\n");
	busca(l, 1);
	busca(l, 2);
	busca(l, 3);
	busca(l, 4);
	busca(l, 5);
	busca(l, 6);
	libera(l);
	
	return 0;
}

// Desenvolvimento das funções
Lista* insere (Lista* l, int v)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	if (l != NULL)
	{
		novo->prox = l;
		if (novo->prox->prox == l)
		{
			l->prox = novo;
		}
		else
		{
			Lista* p = l;
			Lista* f = NULL;
			while (p != f)
			{
				if (f == NULL)
				{
					f = p;
				}
				if (p->prox == f)
				{
					p->prox = novo;
					break;	
				}
				p = p->prox;
			}
		}
	}
	else
	{
		novo->prox = novo;
	}
	return novo;
}

void imprime (Lista* l)
{
	Lista* p = l;
	Lista* f = NULL;
	while (p != f)
	{
		if (f == NULL)
		{
			f = p;
		}
		printf("%d | info: %d | prox: %d \n", p, p->info, p->prox);
		p = p->prox;
	}
}


Lista* busca (Lista* l, int v)
{
	Lista* p = l;
	Lista* f = NULL;
	while (p != f)
	{
		if (f == NULL)
		{
			f = p;
		}
		if (p->info == v)
		{
			printf("%d foi encontrado \n", v);
			return p;
		}
		p = p->prox;
	}
	printf("%d nao foi encontrado \n", v);
	return NULL;
}

Lista* retira (Lista* l, int v)
{
	Lista* ant = NULL;
	Lista* p = l;
	Lista* f = NULL;
	
	while (p != f && p->info != v)
	{
		if (f == NULL)
		{
			f = p;
		}
		ant = p;
		p = p->prox;
	}
			
	if (p == NULL)
	{
		return l;
	}
	if (ant == NULL)
	{
		Lista* p2 = l;
		f = NULL;
		l = p->prox;
		while (p2 != f)
		{
			if (f == NULL)
			{
				f = p2;
			}
			if (p2->prox == f)
			{
				p2->prox = l;
				break;	
			}
			p2 = p2->prox;
		}
	}
	else
	{
		ant->prox = p->prox;	
	}
	free(p);
	return l;
}

void libera(Lista* l)
{
	Lista* p = l;
	Lista* t = NULL;
	Lista* f = NULL;
	
	while (p != f)
	{
		if (f == NULL)
		{
			f = p;
		}
		t = p->prox;
		free(p);
		p = t;
	}
}

