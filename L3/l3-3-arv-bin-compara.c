#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv;

// Protótipo das funções
Arv* inicializa (void);
int vazia (Arv* r);
Arv* insere (Arv* r, int v);
void percorrer (Arv* r, Arv* s, int *pn);
int iguais (Arv* r, Arv* s); // O para TRUE e 1 para FALSE
Arv* libera (Arv* r);

// Função Main
int main (void)
{
	Arv* a = inicializa();
	a = insere(a, 1);
	a = insere(a, 2);
	a = insere(a, 3);
	a = insere(a, 4);
	a = insere(a, 6);
	a = insere(a, 8);
	a = insere(a, 5);
	
	Arv* b = inicializa();
 	b = insere(b, 1);
 	b = insere(b, 2);
 	b = insere(b, 3);
	b = insere(b, 4);
 	b = insere(b, 6);
 	b = insere(b, 8);
 	b = insere(b, 5);
	
	printf("IGUAIS: %d", iguais(a, b));
	
	libera(a);
	
	return 0;
}

// Desenvolvimento das funções
Arv* inicializa (void)
{	
	return NULL;
}

int vazia (Arv* r)
{
	return r == NULL;
}

Arv* insere (Arv* r, int v)
{
	if (r == NULL)
	{
		r = (Arv*) malloc(sizeof(Arv));
		r->info = v;
		r->esq = r->dir = NULL;
	}
	else if (v < r->info)
	{
		r->esq = insere(r->esq, v);
	}
	else
	{
		r->dir = insere(r->dir, v);
	}
	
	return r;
}

void percorrer (Arv* r, Arv* s, int *pn)
{
	if ((r != NULL && s == NULL) || (r == NULL && s != NULL))
	{
		*pn = 1;
	}
	if (!vazia(r) && !vazia(s))
	{
		int infor = r->info;
		int infos = s->info;
		if (infor != infos)
		{
			*pn = 1;
		}
		
		percorrer(r->esq, s->esq, pn);
		percorrer(r->dir, s->dir, pn);
	}
}

int iguais (Arv* r, Arv* s)
{
	int e = 0;
	if ((r != NULL && s == NULL) || (r == NULL && s != NULL))
	{
		e = 1;
		
		return e;
	}
	else
	{
		percorrer(r, s, &e);				
	}
	
	return e;	
}

Arv* libera (Arv* r)
{
	if (!vazia(r))
	{
		libera(r->esq); // Libera sae
		libera(r->dir); // Libera sad
		free(r); // Libera raiz
	}
}

