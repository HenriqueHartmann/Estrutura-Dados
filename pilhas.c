#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

struct pilha {
	int info;
	struct pilha* prox;
};

typedef struct pilha Pilha;

Pilha* inicializa (void)
{
	return NULL;
}

void imprime (Pilha* p)
{
	Pilha* q;
	for (q = p; q != NULL; q = q->prox)
	{
		printf("info: %d prox: %d \n", q->info, q->prox);
	}
}

int vazia (Pilha* p)
{
	return (p==NULL);
}

void libera (Pilha* p)
{
	Pilha* q = p;
	while (q != NULL)
	{
		Pilha * t = q->prox;
		free(q);
		q = t;
	}
}

Pilha* push (Pilha* p, int v)
{	
	Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
	novo->info = v;
	novo->prox = p;
	
	return novo;	
}

int pop (Pilha** p)
{
	Pilha* primeiro = *p;
	int r = primeiro->info;
	*p = primeiro->prox;
	free(primeiro);
	
	return r;
}

int main (void)
{
	Pilha *p;
	p = inicializa();
	p = push(p, 10);
	p = push(p, 30);
	p = push(p, 40);
	
	imprime(p);
	printf("Valor Removido do Topo = %d \n", pop(&p));	
	imprime(p);
	libera(p);
	
	return 0;
}

