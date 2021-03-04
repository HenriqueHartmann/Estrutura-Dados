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
void imprime (Arv* r);
Arv* insere (Arv* r, int v);
Arv* busca (Arv* r, int v);
Arv* retira (Arv* r, int v);
void percorrer (Arv* r, int *p);
int contarNos (Arv* r);
int maior (int x, int y);
int calcularAltura (Arv* r);
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
	
	// imprime(a);
	int c = contarNos(a);
	int rst = calcularAltura(a);
	printf("QTD NOS: %d \n", c);
	printf("ALTURA: %d \n", rst);
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

void imprime (Arv* r)
{
	if (!vazia(r))
	{
		imprime(r->esq); // Mostra sae
		printf("%d\n ", r->info); // Mostra a raiz
		imprime(r->dir); // Mostra sad
	}
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

Arv* busca (Arv* r, int v)
{
	if (r == NULL)
	{
		return NULL;
	}
	else if (v < r->info)
	{
		return busca(r->esq, v);
	}
	else if (v > r->info)
	{
		return busca(r->dir, v);
	}
	else
	{
		return r;
	}
}

Arv* retira (Arv* r, int v)
{
	if (r == NULL)
	{
		return NULL;
	}
	else if (v < r->info)
	{
		r->esq = retira(r->esq, v);
	}
	else if (v > r->info)
	{
		r->dir = retira(r->dir, v);
	}
	else
	{
		if (r->esq == NULL && r->dir == NULL)
		{
			free(r);
			r = NULL;
		}
		else if (r->esq == NULL)
		{
			Arv* t = r;
			r = r->dir;
			free(t);
		}
		else if (r->dir == NULL)
		{
			Arv* t = r;
			r = r->esq;
			free(t);
		}
		else
		{
			Arv* pai = r;
			Arv* f = r->esq;
			while (f->dir != NULL)
			{
				pai = f;
				f = f->dir;
			}
			r->info = f->info;
			f->info = v;
			r->esq = retira(r->esq, v);
		}
	}
	
	return r;
}

void percorrer (Arv* r, int *pn)
{
	if (!vazia(r))
	{
		*pn += 1;
		percorrer(r->esq, pn);
		percorrer(r->dir, pn);
	}
}

int contarNos (Arv* r)
{
	int c = 0;
	percorrer(r, &c);
	
	return c;
}

int maior (int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int calcularAltura (Arv* r)
{
	if ((r == NULL) || (r->esq == NULL && r->dir == NULL))
	{
		return 0;
	}
	else
	{
		int rst = maior(calcularAltura(r->esq), calcularAltura(r->dir)) + 1;
		
		return rst;
	}
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

