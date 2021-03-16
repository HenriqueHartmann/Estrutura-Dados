#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

// Agrupa a variavel char info e os ponteiros esq e dir do tipo arv e cria um novo tipo de variavel
struct arv {
	char info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv; // Renomeia a estrutura arv para Arv

// Protótipo das funções
Arv* inicializa (void); // Inicializa um árvore vazia
int vazia (Arv* r); // Verifica se a árvore é NULL
Arv* cria (char c, Arv* sae, Arv* sad); // Cria um nó raiz e duas sub-árvores, esquerda e direita
int contaNaoFolhas (Arv* r); // Conta os nós não folhas
void libera (Arv* r); // Libera a memória alocada pela árvore

// Função Main
int main (void)
{
Arv* a = cria('1', cria('2',
						cria('7', inicializa(), inicializa()),
						cria('4', inicializa(), inicializa())
						),
				   cria('3',
						cria('5', inicializa(), inicializa()),
						cria('6', inicializa(), cria('8', inicializa(), inicializa()))
						)
					);
	
	printf("\n NAO FOLHAS: %d \n", contaNaoFolhas(a));
	
	libera(a);
	
	return 0;
}

// Desenvolvimento das funções
Arv* inicializa (void)
{	
	return NULL; // Retorna NULL
}

int vazia (Arv* r)
{
	return r == NULL; // Retorna 1 se vazia
}

Arv* cria (char c, Arv* sae, Arv* sad)
{
	Arv* p = (Arv*) malloc(sizeof(Arv)); // Aloca dinamicamente uma árvore
	p->info = c; // Atribui o valor de um nó com c
	p->esq = sae; // Atribui a sub-árvore da esquerda com sae
	p->dir = sad; // Atribui a sib-árvore da direita com dir
	return p; // Retorna p
}

int contaNaoFolhas (Arv* r)
{
	if (vazia(r)) // Verifica se r é NULL, se sim retorna 0
	{
		return 0;	
	}
	int fesq = 0; // Declara e atribui a variavel inteira fesq igual a 0
	int fdir = 0; // Declara e atribui a variavel inteira fdir igual a 0
	int i = 0; // Declara e atribui a variavel inteira i igual a 0
	if (!vazia(r->esq) || !vazia(r->dir)) // Verifica se sae ou sad de r não são NULL, se sim adiciona + 1 a i
	{
		i++;
	}
	fesq = contaNaoFolhas(r->esq); // Declara a variavel fesq como inteira e atribui o valor de retorno da função contaNaoFolhas da esquerda de r
	fdir = contaNaoFolhas(r->dir); // Declara a variavel fdir como inteira e atribui o valor de retorno da função contaNaoFolhas da direita de r
	
	return (fesq + fdir + i); // Retorna a soma das variaveis fesq, fdir e i
}

void libera (Arv* r)
{
	if (!vazia(r)) // Verifica se r não é NULL, se sim executa o código 
	{
		libera(r->esq); // Libera sae
		libera(r->dir); // Libera sad
		free(r); // Libera raiz
	}
}
