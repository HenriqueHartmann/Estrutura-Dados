#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
	int matricula;
	char nome[30];
	float n1, n2, n3;
};
typedef struct aluno Aluno;

struct hash {
	int qtd, TABLE_SIZE;
	Aluno **itens;
};
typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash* ha);

int chaveDivisao(int chave, int TABLE_SIZE);

int insereHash_SemColisao(Hash* ha, Aluno al);

int buscaHash_SemColisao(Hash* ha, int mat, Aluno* al);

int removeHash_SemColisao(Hash* ha, int mat);

