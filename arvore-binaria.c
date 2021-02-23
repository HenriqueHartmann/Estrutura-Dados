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
Arv* cria (char c, Arv* sae, Arv* sad);
int vazia (Arv* a);
void imprime (Arv* a);
Arv* libera (Arv* a);
int busca (Arv* a, char c);

// Função Main
int main (void)
{
	Arv* a1 = cria('d', inicializa(), inicializa()); // sub-árvore com 'd'
	Arv* a2 = cria('b', inicializa(), a1); // sub-árvore com 'b'
	Arv* a3 = cria('e', inicializa(), inicializa()); // sub-árvore com 'e'
	Arv* a4 = cria('f', inicializa(), inicializa()); // sub-árvore com 'f'
	Arv* a5 = cria('c', a3, a4); // sub-árvore com 'c'
	Arv* a = cria('d', a2, a5); // árvore com raiz 'a'
	
	// OU
	
	/*
		Arv* a = cria('a', cria('b',
								inicializa(),
								cria('d', inicializa(), inicializa())),
							cria('c',
								cria('e', inicializa(), inicializa()),
								cria('f', inicializa(), inicializa())
							)
					);
	*/
	
	imprime(a);
	
	// EXERCÍCIO ----------------------------------------------+
	a->esq->esq = cria('x',
						cria('y', inicializa(), inicializa()),
						cria('z', inicializa(), inicializa())
					);
	
	a->dir->esq = libera(a->dir->esq);
	// -------------------------------------------------------+
	printf("\n");
	imprime(a);
	libera(a);
	
	return 0;
}

// Desenvolvimento das funções
Arv* inicializa (void)
{	
	return NULL;
}

Arv* cria (char c, Arv* sae, Arv* sad)
{
	Arv* p = (Arv*) malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

int vazia (Arv* a)
{
	return a == NULL;
}

void imprime (Arv* a)
{
	if (!vazia(a))
	{
		printf("%c ", a->info); // Mostra a raiz
		imprime(a->esq); // Mostra sae
		imprime(a->dir); // Mostra sad
	}
}

Arv* libera (Arv* a)
{
	if (!vazia(a))
	{
		libera(a->esq); // Libera sae
		libera(a->dir); // Libera sad
		free(a); // Libera raiz
	}
}

int busca (Arv* a, char c)
{
	if (!vazia(a))
	{
		return 0; // Árvore vazia: não encontrado
	}
	else
	{
		return a->info == c || busca(a->esq, c) || busca(a->dir, c);
	}
}

