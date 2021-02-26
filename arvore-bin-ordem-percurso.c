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
void imprime (Arv* a, int ordem); // Ordem: 1 - pre-ordem | 2 - ordem-simetrica | 3 - pos-ordem | Outros - pre-ordem => default
void imprimeAll (Arv* a);
Arv* libera (Arv* a);

// Função Main
int main (void)
{
	/* Exemplo - aula
	Arv* a = cria('a', 
				cria('b',
					cria('d', inicializa(), inicializa()),
					inicializa()),
				cria('c',
					cria('e',
						inicializa(),
						cria('g', inicializa(), inicializa())),
					cria('f', 
						cria('h', inicializa(), inicializa()),
						cria('i', inicializa(), inicializa()))
					)
				);
	*/
	
	// Exercícios
	// 1
	Arv* um = cria('a',  
					cria('b',
						inicializa(),
						cria('c', inicializa(), inicializa())
						),
					cria('d',
						cria('e',
							cria('f', inicializa(), inicializa()),
							cria('g', inicializa(), inicializa())
							),
						cria('h', 
							cria('i', inicializa(), inicializa()),
							inicializa()
							)
						)
					);
	imprimeAll(um);
	
	// 2
	Arv* dois = cria('a', 
					cria('b',
						cria('d', inicializa(), inicializa()),
						inicializa()
						),
					cria('c',
						cria('e', inicializa(), inicializa()),
						cria('f', inicializa(), inicializa())
						)
					);
	imprimeAll(dois);
	
	// 3
	Arv* tres = cria('+',  
					cria('*',
						cria('+',
							cria('3', inicializa(), inicializa()),
							cria('6', inicializa(), inicializa())),
						cria('-',
							cria('4', inicializa(), inicializa()),
							cria('1', inicializa(), inicializa()))
						),
					cria('5', inicializa(), inicializa())
					);
	imprimeAll(tres);
	

	
	libera(um);
	libera(dois);
	libera(tres);
	
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

void imprime (Arv* a, int ordem)
{
	if (!vazia(a))
	{
		switch (ordem)
		{
			case 1: // pre-ordem
				printf("%c ", a->info); // Mostra a raiz
				imprime(a->esq, ordem); // Mostra sae
				imprime(a->dir, ordem); // Mostra sad
				break;
			case 2: // ordem-simetrica
				imprime(a->esq, ordem); // Mostra sae
				printf("%c ", a->info); // Mostra a raiz
				imprime(a->dir, ordem); // Mostra sad
				break;
			case 3: // pos-ordem
				imprime(a->esq, ordem); // Mostra sae
				imprime(a->dir, ordem); // Mostra sad
				printf("%c ", a->info); // Mostra a raiz
				break;
			default: // default = pre-ordem
				printf("%c ", a->info); // Mostra a raiz
				imprime(a->esq, ordem); // Mostra sae
				imprime(a->dir, ordem); // Mostra sad
				break;	
		}
	}
}

void imprimeAll (Arv* a)
{
	printf("\n pre-ordem: ");
	imprime(a, 1);
	printf("\n in-ordem: ");
	imprime(a, 2);
	printf("\n pos-ordem: ");
	imprime(a, 3);
	printf("\n ");
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

