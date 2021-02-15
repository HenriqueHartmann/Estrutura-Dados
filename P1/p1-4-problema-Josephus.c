#include <stdlib.h>
#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

// Agrupa a variavel inteira info e o ponteiro prox do tipo lista e cria um novo tipo de variavel
struct lista {
	int info;
	struct lista* prox;
};

typedef struct lista Lista; // Renomeia a estrutura lista para Lista

// Protótipo das funções
Lista* insere (Lista* l, int v); // Insere um novo valor no início da Lista e a retorna com o elemento adicionado
Lista* insereAll (int n); // Insere invertidamente uma sequência de números inteiros em uma Lista e a retorna com os elementos adicionados
Lista* busca (Lista* l, int v); // Busca um elemento numa Lista
Lista* retira (Lista* l, int v); // Remove um elemento de uma Lista
void libera(Lista* l); // Libera a Lista da memória
int josephus (int n, int k); // Resolve o problema de Josephus

// Funçao Main
int main (void)
{
	// Chama a função josephus
	josephus(5, 2); // Retornará 3
	josephus(6, 3); // Retornará 1
	josephus(7, 3); // Retornará 4
	
	// Fim do programa
	return 0;
}

// Desenvolvimento das funções
Lista* insere (Lista* l, int v)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista)); // Declara novo como tipo Lista e atribui seu valor a alocação dinâmica
	novo->info = v; // Atribui o valor de v ao elemento info de novo 
	if (l != NULL) // Caso a lista esteja vazia
	{
		novo->prox = l; // O elemento prox de novo recebe o primeiro elemento da Lista l
		if (novo->prox->prox == l) // Caso o próximo elemento do elemento prox de novo seja igual ao primeiro elemento da Lista l
		{
			l->prox = novo; // É atribuído o valor de novo ao elemento prox do primeiro elemento da Lista l
		}
		else // Caso a condição seja falsa
		{
			Lista* p = l; // Declara p como Lista e p recebe l
			Lista* f = NULL; // Declara f como lista e f recebe NULL
			while (p != f) // Enquanto p for diferente de f
			{
				if (f == NULL) // Caso f seja igual a NULL
				{
					f = p; // f recebe p
				}
				if (p->prox == f) // Caso o elemento prox de p for igual a f
				{
					p->prox = novo; // O elemento prox de p recebe novo
					break; // Encerra o loop
				}
				p = p->prox; // p recebe o elemento prox de p
			}
		}
	}
	else // Caso a condição seja falsa
	{
		novo->prox = novo; // O elemento prox de novo recebe novo;
	}
	return novo; // Retorna novo
}

Lista* insereAll (int n)
{
	Lista* nova = NULL; // Declara a variavel nova do tipo Lista e atribui seu valor como NULL
	int i = n; // Declara a variavel i como inteira e atribui seu valor igual a n
	for (i; i > 0; i--) // Cria um loop controlado onde i deve ser maior que 0 e a cada passagem é incrementado - 1
	{
		nova = insere(nova, i); // A variavel nova recebe o retorno de insere
	}
	return nova; // Retorna a variavel nova
}

Lista* busca (Lista* l, int v)
{
	Lista* p = l; // Declara a variavel p do tipo Lista que recebe l
	Lista* f = NULL; // Declara a variavel f do tipo Lista que recebe NULL
	while (p != f) // Executa o código enquanto p for diferente de f
	{
		if (f == NULL) // Se f for igual a NULL, f recebe p
		{
			f = p; // f recebe p
		}
		if (p->info == v) // Se o elemento info de p for igual a v, retorne p
		{
			return p; // Retorna p
		}
		p = p->prox; // p recebe elemento prox de p
	}
	return NULL; // Retorna NULL
}

Lista* retira (Lista* l, int v)
{
	Lista* ant = NULL; // Declara a variavel ant do tipo Lista igual a NULL
	Lista* p = l; // Declara a variavel p do tipo Lista igual a l
	Lista* f = NULL; // Declara a variavel f do tipo Lista igual a NULL
	
	while (p != f && p->info != v) // Execute o código enquanto p for diferente de f e o elemento info de p diferente de v
	{
		if (f == NULL) // Se f for igual a NULL, f recebe p
		{
			f = p; // f recebe p
		}
		ant = p; // ant recebe p
		p = p->prox; // p recebe o elemento prox de p
	}
			
	if (p == NULL) // Se p for igual a NULL, retorne l
	{
		return l; // Retorna l
	}
	if (ant == NULL) // Se ant for igual a NULL
	{
		Lista* p2 = l; // Declara p2 do tipo Lista igual a l
		f = NULL; // f recebe NULL
		l = p->prox; // l recebe elemento prox de p
		while (p2 != f) // Execute o código enquanto p2 for diferente de f
		{
			if (f == NULL) // Se f for igual a NULL, f recebe p2
			{
				f = p2; // f recebe p2
			}
			if (p2->prox == f) // Se elemento prox de p2 for igual a f, elemento prox de p2 recebe l e encerra o loop
			{
				p2->prox = l; // Elemento prox de p2 recebe l
				break; // Encerra o loop
			}
			p2 = p2->prox; // p2 recebe o elemento prox de p2
		}
	}
	else // Se não, o elemento prox de ant for igual o elemento prox de p
	{
		ant->prox = p->prox; // Elemento prox de ant recebe o elemento prox de p
	}
	free(p); // Libera a memória apontada para p
	return l; // Retorna l
}

void libera(Lista* l)
{
	Lista* p = l; // Declara p do tipo Lista que recebe l
	Lista* t = NULL; // Declara t do tipo Lista que recebe NULL
	Lista* f = NULL; // Declara f do tipo Lista que recebe NULL
	
	while (p != f) // Execute o código enquanto p for diferente de f
	{
		if (f == NULL) // Se f for igual a NULL, f recebe p
		{
			f = p; // f recebe p
		}
		t = p->prox; // t recebe o elemento prox de p
		free(p); // Libera a memória apontada para p
		p = t; // p recebe t
	}
}

int josephus (int n, int k)
{
	Lista* l = insereAll(n); // Declara l do tipo Lista que recebe o retorno da função insereAll
	Lista* e = busca(l, n); // Declara e do tipo Lista que recebe o retorno da função busca
	Lista* p = e; // Declara p do tipo Lista que recebe e
	int count = n; // Declara i do tipo inteiro que recebe n
	int temp = 1; // Declara temp do tipo inteiro que recebe 1
	
	while (count != 1) // Executa o código enquanto count for diferente de 1
	{
		while (temp <= k) // Executa o código enquanto tempo for menor ou igual a k
		{
			p = p->prox; // p recebe o elemento prox de p
			temp++; // Incrementa + 1 na variavel inteira temp
		}
		Lista* ptemp = p->prox; // Declara a variavel ptemp do tipo Lista que recebe o elemento prox de p
		l = retira(l, p->info); // l recebe o retorno da função retira
		temp = 2; // temp recebe 2
		p = ptemp; // p recebe p temp
		count--; // count incrementa - 1
	}
	int r = l->info; // Declara a variavel r do tipo inteiro que recebe o elemento info de l
	libera(l); // Chama a função libera para liberar da memória os elementos de l
	printf("INFO: %d \n", r); // Imprime a mensagem com a variavel r
	return r; // Retorna r
}

