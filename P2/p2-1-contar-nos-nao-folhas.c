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

// Prot�tipo das fun��es
Arv* inicializa (void); // Inicializa um �rvore vazia
int vazia (Arv* r); // Verifica se a �rvore � NULL
Arv* cria (char c, Arv* sae, Arv* sad); // Cria um n� raiz e duas sub-�rvores, esquerda e direita
int contaNaoFolhas (Arv* r); // Conta os n�s n�o folhas
void libera (Arv* r); // Libera a mem�ria alocada pela �rvore

// Fun��o Main
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

// Desenvolvimento das fun��es
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
	Arv* p = (Arv*) malloc(sizeof(Arv)); // Aloca dinamicamente uma �rvore
	p->info = c; // Atribui o valor de um n� com c
	p->esq = sae; // Atribui a sub-�rvore da esquerda com sae
	p->dir = sad; // Atribui a sib-�rvore da direita com dir
	return p; // Retorna p
}

int contaNaoFolhas (Arv* r)
{
	if (vazia(r)) // Verifica se r � NULL, se sim retorna 0
	{
		return 0;	
	}
	int fesq = 0; // Declara e atribui a variavel inteira fesq igual a 0
	int fdir = 0; // Declara e atribui a variavel inteira fdir igual a 0
	int i = 0; // Declara e atribui a variavel inteira i igual a 0
	if (!vazia(r->esq) || !vazia(r->dir)) // Verifica se sae ou sad de r n�o s�o NULL, se sim adiciona + 1 a i
	{
		i++;
	}
	fesq = contaNaoFolhas(r->esq); // Declara a variavel fesq como inteira e atribui o valor de retorno da fun��o contaNaoFolhas da esquerda de r
	fdir = contaNaoFolhas(r->dir); // Declara a variavel fdir como inteira e atribui o valor de retorno da fun��o contaNaoFolhas da direita de r
	
	return (fesq + fdir + i); // Retorna a soma das variaveis fesq, fdir e i
}

void libera (Arv* r)
{
	if (!vazia(r)) // Verifica se r n�o � NULL, se sim executa o c�digo 
	{
		libera(r->esq); // Libera sae
		libera(r->dir); // Libera sad
		free(r); // Libera raiz
	}
}
