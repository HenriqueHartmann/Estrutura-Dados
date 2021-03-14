#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

struct arv {
	char info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv;

// Protótipo das funções
Arv* inicializa (void);
int vazia (Arv* r);
Arv* insere (Arv* r, int v);
int contaFolhas (Arv* r);
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
	
	printf("FOLHAS: %d", contarFolhas(a));
	
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

int contarFolhas (Arv* r)
{
	if (r == NULL)
	{
		return 0;	
	}
	if (r->esq == NULL && r->dir == NULL)
	{
		return 1;
	}
	int fesq = contarFolhas(r->esq);
	int fdir = contarFolhas(r->dir);
	
	return (fesq + fdir);
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

