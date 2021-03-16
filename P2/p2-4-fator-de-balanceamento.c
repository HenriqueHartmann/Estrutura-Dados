#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

// Agrupa a variavel inteira info e os ponteiros esq e dir do tipo arv e cria um novo tipo de variavel
struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv; // Renomeia a estrutura arv para Arv

// Prot�tipo das fun��es
Arv* inicializa (void); // Inicializa um �rvore vazia
int vazia (Arv* r); // Verifica se a �rvore � NULL
Arv* insere (Arv* r, int v); // Insere um novo elemento na �rvore
Arv* busca (Arv* r, int v); // Retorna um elemento espec�fico da �rvore
int maior (int x, int y); // Verifica se x � maior que y, e retorna o maior
int calcularAltura (Arv* r); // Calcula altura de um n�
int fb (Arv* r, int v); // Calcula o fator de balanceamento de um n�
Arv* libera (Arv* r); // Libera a mem�ria alocada pela �rvore

// Fun��o Main
int main (void)
{
	Arv* arv = inicializa(); // Declara arv do tipo Arv que recebe o retorno de inicializa()
	arv = insere(arv, 20); // 20 � inserido em arv
	arv = insere(arv, 21); // 21 � inserido em arv
	arv = insere(arv, 22); // 22 � inserido em arv
	arv = insere(arv, 23); // 23 � inserido em arv
	arv = insere(arv, 19); // 19 � inserido em arv
	arv = insere(arv, 18); // 18 � inserido em arv
	arv = insere(arv, 17); // 17 � inserido em arv
	
	fb(arv, 20); // Calcula o fator de balanceamento do n� 20, espera-se: +0
	fb(arv, 19); // Calcula o fator de balanceamento do n� 19, espera-se: -2
	fb(arv, 21); // Calcula o fator de balanceamento do n� 21, espera-se: +2
	fb(arv, 18); // Calcula o fator de balanceamento do n� 18, espera-se: -1
	fb(arv, 22); // Calcula o fator de balanceamento do n� 22, espera-se: +1
	fb(arv, 17); // Calcula o fator de balanceamento do n� 17, espera-se: +0
	fb(arv, 23); // Calcula o fator de balanceamento do n� 23, espera-se: +0
	
	libera(arv); // Chama libera da mem�ria os n�s de arv
	
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

Arv* insere (Arv* r, int v)
{
	if (r == NULL) // Se r for igual a NULL, se sim executa o c�digo
	{
		r = (Arv*) malloc(sizeof(Arv)); // Declara r como tipo Arv e atribui seu valor a aloca��o din�mica
		r->info = v; // Atribui o valor de v ao elemento info de r
		r->esq = r->dir = NULL; // O n� esquerdo e direito de r recebe NULL
	}
	else if (v < r->info) // Caso v for menor que o elemento info de r o n� esquerdo de r recebe insere com os par�metros => n� esquerdo de r e o inteiro v
	{
		r->esq = insere(r->esq, v);
	}
	else // Se n�o o n� direito de r recebe insere com os par�metros => n� direito de r e o inteiro v
	{
		r->dir = insere(r->dir, v);
	}
	
	return r; // Retorna r
}

Arv* busca (Arv* r, int v)
{
	if (r == NULL) // Se r � igual a NULL, retorna NULL
	{
		return NULL;
	}
	else if (v < r->info) // Caso v for menor que o elemento info de r, retorna a fun��o busca do n� esquerdo de r na busca de v
	{
		return busca(r->esq, v);
	}
	else if (v > r->info) // Caso v for maior que o elemento info de r, retorna a fun��o busca do n� direito de r na busca de v
	{
		return busca(r->dir, v);
	}
	else // Se n�o retorna r
	{
		return r;
	}
}

int maior (int x, int y)
{
	if (x > y) // Verifica se x � maior que y e retorna o maior
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
	if ((r == NULL) || (r->esq == NULL && r->dir == NULL)) // Verifica se r � NULL ou a sub-�rvore da esquerda e direita igual a NULL, se sim retorna 0
	{
		return 0;
	}
	else // Se n�o
	{
		// Declara a variavel inteira rst e atribui seu valor igual ao retorno da fun��o maior que usa como par�metros a fun��o calcularAltura nas sub-�rvores da esquerda e direita ...
		int rst = maior(calcularAltura(r->esq), calcularAltura(r->dir)) + 1; // E soma mais um
		
		return rst; // Retorna rst
	}
}

int fb (Arv* r, int v)
{
	Arv* n = busca(r, v); // Declara n como Arv e atribui ao valor de retorno da fun��o busca
	int hesq = 0; // Declara hesq como inteiro e atribui seu valor igual a 0
	int hdir = 0; // Declara hdir como inteiro e atribui seu valor igual a 0
	if (!vazia(n->esq)) // Verifica se o n� esqurdo de n n�o � NULL, se sim executa o c�digo
	{
		hesq = calcularAltura(n->esq) + 1; // Atribui hesq igual ao retorno da fun��o calcularAltura no n� esquerdo de n e soma + 1 
	}
	if (!vazia(n->dir)) // Verifica se o n� direito de n n�o � NULL, se sim executa o c�digo
	{
		hdir = calcularAltura(n->dir) + 1; // Atribui hdir igual ao retorno da fun��o calcularAltura no n� direito de n e soma + 1
	}
	printf("%d | FB: %d \n", n->info, (hdir - hesq)); // Imprime o fator de balanceamento
	
	return (hdir - hesq); // Retorna o fator de balanceamento
}

Arv* libera (Arv* r)
{
	if (!vazia(r)) // Verifica se r n�o � NULL, se sim executa o c�digo
	{
		libera(r->esq); // Libera sae
		libera(r->dir); // Libera sad
		free(r); // Libera raiz
	}
}

