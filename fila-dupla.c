#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

struct no {
	int info;
	struct no* prox;
	struct no* ant;
};
typedef struct no No;

struct deque {
	No* ini;
	No* fim;
};
typedef struct deque Deque;

// Protótipo das funções
Deque* cria (void);
void imprime (Deque* d);
Deque* insereIni (Deque* d, int v);
Deque* insereFim (Deque* d, int v);
int retiraIni (Deque* d);
int retiraFim (Deque* d);
int vazia (Deque* d);
void libera (Deque* d);

// Função Main
int main (void)
{
	Deque* d = cria();
	d = insereIni(d, 1);
	d = insereIni(d, 2);
	d = insereFim(d, 3);
	printf("%d foi removido\n", retiraIni(d));
	printf("%d foi removido\n", retiraFim(d));
	imprime(d);
	libera(d);
	
	return 0;
}

Deque* cria (void)
{
	Deque* d = (Deque*) malloc(sizeof(Deque));
	d->ini = d->fim = NULL;
	return d;
}

void imprime (Deque* d)
{
	No* q;
	for (q = d->ini; q != NULL; q = q->prox)
	{
		printf("%d \n", q->info);
	}
}

Deque* insereIni (Deque* d, int v)
{
	No* novo = (No*) malloc(sizeof(No));
	novo->info = v;
	novo->prox = NULL;
	novo->ant = NULL;
	if (d->ini != NULL)
	{
		d->ini->ant = novo;
		novo->prox = d->ini;	
	}
	
	d->ini = novo;
	if (d->fim == NULL)
	{
		d->fim = d->ini;
	}
	
	return d;
}

Deque* insereFim (Deque* d, int v)
{
	No* novo = (No*) malloc(sizeof(No));
	novo->info = v;
	novo->prox = NULL;
	novo->ant = NULL;
	if (d->fim != NULL)
	{
		d->fim->prox = novo;
		novo->ant = d->fim;
	}
	
	d->fim = novo;
	if (d->ini == NULL)
	{
		d->ini = d->fim;
	}
	
	return d;
}

int retiraIni (Deque* d)
{
	int v;
	if (vazia(d))
	{
		printf("Fila vazia.\n");
		exit(1);
	}
	v = d->ini->info;
	No* p = d->ini->prox;
	p->ant = NULL;
	free(d->ini);
	d->ini = p;
	if (d->ini == NULL)
	{
		d->fim = NULL;
	}
	
	return v;
}

int retiraFim (Deque* d)
{
	int v;
		if (vazia(d))
	{
		printf("Fila vazia.\n");
		exit(1);
	}
	v = d->fim->info;
	No* p = d->fim->ant;
	p->prox = NULL;
	free(d->fim);
	d->fim = p;
	if (d->ini == NULL)
	{
		d->fim = NULL;
	}
	
	return v;
}

int vazia (Deque* d)
{
	return (d->ini == NULL);
}

void libera (Deque* d)
{
	No* q = d->ini;
	while (q != NULL)
	{
		No* t = q->prox;
		free(q);
		q = t;
	}
	
	free(d);
}

