#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

struct no {
	int info;
	struct no* prox;
};
typedef struct no No;

struct fila {
	No* ini;
	No* fim;
};
typedef struct fila Fila;

// Protótipo das funções
Fila* cria (void);
Fila* insere (Fila* f, int v);
void imprime (Fila* f);
int retira (Fila* f);
int vazia (Fila* f);
void libera (Fila* f);

// Função Main
int main (void)
{
	Fila * f = cria();
	f = insere(f, 1);
	f = insere(f, 2);
	f = insere(f, 3);
	retira(f);
	imprime(f);
	libera(f);
	
	return 0;
}

// Desenvolvimento das funções
Fila* cria (void)
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

Fila* insere (Fila* f, int v)
{
	No* novo = (No*) malloc(sizeof(No));
	novo->info = v;
	novo->prox = NULL;
	if (f->fim != NULL)
	{
		f->fim->prox = novo;
	}
	
	f->fim = novo;
	if (f->ini == NULL)
	{
		f->ini = f->fim;
	}
	
	return f;
}

void imprime (Fila* f)
{
	No* q;
	for (q = f->ini; q != NULL; q = q->prox)
	{
		printf("%d \n", q->info);
	}
}

int retira (Fila* f)
{
	int v;
	if (vazia(f))
	{
		printf("Fila vazia.\n");
		exit(1);
	}
	v = f->ini->info;
	No* p = f->ini->prox;
	free(f->ini);
	f->ini = p;
	if (f->ini == NULL)
	{
		f->fim = NULL;
	}
	
	return v;
}

int vazia (Fila* f)
{
	return (f->ini==NULL);
}

void libera (Fila* f)
{
	No* q = f->ini;
	while (q != NULL)
	{
		No* t = q->prox;
		free(q);
		q = t;
	}
	
	free(f);
}

