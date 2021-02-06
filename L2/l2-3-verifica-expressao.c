#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

struct pilha {
	char info;
	struct pilha* prox;
};

typedef struct pilha Pilha;

// Protótipo das funções
Pilha* push (Pilha* p, char v);
void pop (Pilha** p);
void libera (Pilha* p);
int countPilha (Pilha* p);
void verifica (char e[]);

int main (void)
{
//	char e[] = "a+(b*c)-2-a";
//	char e[] = "(a+b*(2-c)-2+a)*2";
//	char e[] = "((a*b-(2+c) ";
//	char e[] = "2*(3-a))";
	char e[] = ")3+b*(2-c)(";
	verifica (e);
	
	return 0;
}

Pilha* push (Pilha* p, char v)
{
	Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
	novo->info = v;
	novo->prox = p;
	return novo;
}

void pop (Pilha** p)
{
	Pilha* primeiro = *p;
	*p = primeiro->prox;
	free(primeiro);
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

int countPilha (Pilha* p)
{
	int i = 0;
	Pilha* q;
	for (q = p; q != NULL; q = q->prox)
	{
		i++;
	}
	return i;
}

void verifica (char e[])
{
	Pilha* t = NULL;
	int i;
	int p = 0;
	while (e[i] != '\0')
	{
		if (e[i] == '(')
		{
			t = push(t, '(');
		}
		printf("%c | count: %d | \n", e[i], countPilha(t));
		if (e[i] == ')')
		{
			if (countPilha(t) > 0)
			{
				pop(&t);
			}
			else
			{
				p = 1;
				break;
			}
		}
		i++;
	}
	if (countPilha(t) == 0 && p == 0)
	{
		printf("esta correto\n");
	}
	else
	{
		printf("esta incorreto\n");
	}
	libera(t);
}

