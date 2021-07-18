#include "TabelaHash.h"

Hash* criaHash(int TABLE_SIZE) {
	Hash* ha = (Hash*) malloc(sizeof(Hash));
	if (ha != NULL) {
		int i;
		ha->TABLE_SIZE = TABLE_SIZE;
		ha->itens = (Aluno**) malloc(TABLE_SIZE * sizeof(Aluno*));
		if (ha->itens == NULL) {
			free(ha);
			return NULL;
		}
		ha->qtd = 0;
		for (i = 0; i < ha->TABLE_SIZE; i++)
			ha->itens[i] = NULL;
	}
	return ha;
}

void liberaHash(Hash* ha) {
	if (ha != NULL) {
		int i;
		for (i = 0; i < ha->TABLE_SIZE; i++) {
			if (ha->itens[i] != NULL)
				free(ha->itens[i]);
		}
		free(ha->itens);
		free(ha);
	}
}

int chaveDivisao(int chave, int TABLE_SIZE) {
	return (chave % TABLE_SIZE);
}

int insereHash_SemColisao(Hash* ha, Aluno al) {
	if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
		return 0;

	int chave = al.matricula;
	int pos = chaveDivisao(chave, ha->TABLE_SIZE);
	Aluno* novo;
	novo = (Aluno*) malloc(sizeof(Aluno));

	if(novo == NULL)
		return 0;

	*novo = al;
	ha->itens[pos] = novo;
	ha->qtd++;
	
	return 1;	 
}

int buscaHash_SemColisao(Hash* ha, int mat, Aluno* al) {
	if (ha == NULL)
		return 0;
		
	int pos = chaveDivisao(mat, ha->TABLE_SIZE);
	
	if (ha->itens[pos] == NULL)
		return 0;
	
	*al = *(ha->itens[pos]);
	
	return 1;
}

int removeHash_SemColisao(Hash* ha, int mat) {
	if (ha == NULL)
		return 0;
		
	int pos = chaveDivisao(mat, ha->TABLE_SIZE);
	
	if (ha->itens[pos] == NULL)
		return 0;
		
	free(ha->itens[pos]);
	ha->itens[pos] = NULL;
	
	return 1;
}

