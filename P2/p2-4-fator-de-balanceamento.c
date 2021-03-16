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

// Protótipo das funções
Arv* inicializa (void); // Inicializa um árvore vazia
int vazia (Arv* r); // Verifica se a árvore é NULL
Arv* insere (Arv* r, int v); // Insere um novo elemento na árvore
Arv* busca (Arv* r, int v); // Retorna um elemento específico da árvore
int maior (int x, int y); // Verifica se x é maior que y, e retorna o maior
int calcularAltura (Arv* r); // Calcula altura de um nó
int fb (Arv* r, int v); // Calcula o fator de balanceamento de um nó
Arv* libera (Arv* r); // Libera a memória alocada pela árvore

// Função Main
int main (void)
{
	Arv* arv = inicializa(); // Declara arv do tipo Arv que recebe o retorno de inicializa()
	arv = insere(arv, 20); // 20 é inserido em arv
	arv = insere(arv, 21); // 21 é inserido em arv
	arv = insere(arv, 22); // 22 é inserido em arv
	arv = insere(arv, 23); // 23 é inserido em arv
	arv = insere(arv, 19); // 19 é inserido em arv
	arv = insere(arv, 18); // 18 é inserido em arv
	arv = insere(arv, 17); // 17 é inserido em arv
	
	fb(arv, 20); // Calcula o fator de balanceamento do nó 20, espera-se: +0
	fb(arv, 19); // Calcula o fator de balanceamento do nó 19, espera-se: -2
	fb(arv, 21); // Calcula o fator de balanceamento do nó 21, espera-se: +2
	fb(arv, 18); // Calcula o fator de balanceamento do nó 18, espera-se: -1
	fb(arv, 22); // Calcula o fator de balanceamento do nó 22, espera-se: +1
	fb(arv, 17); // Calcula o fator de balanceamento do nó 17, espera-se: +0
	fb(arv, 23); // Calcula o fator de balanceamento do nó 23, espera-se: +0
	
	libera(arv); // Chama libera da memória os nós de arv
	
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

Arv* insere (Arv* r, int v)
{
	if (r == NULL) // Se r for igual a NULL, se sim executa o código
	{
		r = (Arv*) malloc(sizeof(Arv)); // Declara r como tipo Arv e atribui seu valor a alocação dinâmica
		r->info = v; // Atribui o valor de v ao elemento info de r
		r->esq = r->dir = NULL; // O nó esquerdo e direito de r recebe NULL
	}
	else if (v < r->info) // Caso v for menor que o elemento info de r o nó esquerdo de r recebe insere com os parâmetros => nó esquerdo de r e o inteiro v
	{
		r->esq = insere(r->esq, v);
	}
	else // Se não o nó direito de r recebe insere com os parâmetros => nó direito de r e o inteiro v
	{
		r->dir = insere(r->dir, v);
	}
	
	return r; // Retorna r
}

Arv* busca (Arv* r, int v)
{
	if (r == NULL) // Se r é igual a NULL, retorna NULL
	{
		return NULL;
	}
	else if (v < r->info) // Caso v for menor que o elemento info de r, retorna a função busca do nó esquerdo de r na busca de v
	{
		return busca(r->esq, v);
	}
	else if (v > r->info) // Caso v for maior que o elemento info de r, retorna a função busca do nó direito de r na busca de v
	{
		return busca(r->dir, v);
	}
	else // Se não retorna r
	{
		return r;
	}
}

int maior (int x, int y)
{
	if (x > y) // Verifica se x é maior que y e retorna o maior
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
	if ((r == NULL) || (r->esq == NULL && r->dir == NULL)) // Verifica se r é NULL ou a sub-árvore da esquerda e direita igual a NULL, se sim retorna 0
	{
		return 0;
	}
	else // Se não
	{
		// Declara a variavel inteira rst e atribui seu valor igual ao retorno da função maior que usa como parâmetros a função calcularAltura nas sub-árvores da esquerda e direita ...
		int rst = maior(calcularAltura(r->esq), calcularAltura(r->dir)) + 1; // E soma mais um
		
		return rst; // Retorna rst
	}
}

int fb (Arv* r, int v)
{
	Arv* n = busca(r, v); // Declara n como Arv e atribui ao valor de retorno da função busca
	int hesq = 0; // Declara hesq como inteiro e atribui seu valor igual a 0
	int hdir = 0; // Declara hdir como inteiro e atribui seu valor igual a 0
	if (!vazia(n->esq)) // Verifica se o nó esqurdo de n não é NULL, se sim executa o código
	{
		hesq = calcularAltura(n->esq) + 1; // Atribui hesq igual ao retorno da função calcularAltura no nó esquerdo de n e soma + 1 
	}
	if (!vazia(n->dir)) // Verifica se o nó direito de n não é NULL, se sim executa o código
	{
		hdir = calcularAltura(n->dir) + 1; // Atribui hdir igual ao retorno da função calcularAltura no nó direito de n e soma + 1
	}
	printf("%d | FB: %d \n", n->info, (hdir - hesq)); // Imprime o fator de balanceamento
	
	return (hdir - hesq); // Retorna o fator de balanceamento
}

Arv* libera (Arv* r)
{
	if (!vazia(r)) // Verifica se r não é NULL, se sim executa o código
	{
		libera(r->esq); // Libera sae
		libera(r->dir); // Libera sad
		free(r); // Libera raiz
	}
}

