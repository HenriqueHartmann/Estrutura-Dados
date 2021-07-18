#include "TabelaHash.h"

int main (void)
{
	Hash* hash_main = criaHash(20);
	Aluno al_main;
	Aluno temp;
	
	al_main.matricula = 307381;
	strcpy(al_main.nome, "maria");
	
	/*
	printf("Digite a matricula\n");
	scanf("%d", &al_main.matricula);
	printf("Digite o nome\n");
	scanf("%s", &al_main.nome);
	*/
	
	// Inserir aluno
	int x = insereHash_SemColisao(hash_main, al_main);
	if (x == 1)
		printf("Item inserido com sucesso 1\n");
	else
		printf("Item nao inserido 1\n");
	
	// Buscar aluno
	int y = buscaHash_SemColisao(hash_main, 307381, &temp);
	if (y == 1) {
		printf("\nItem recuperado com sucesso 1\n");
		printf("Matricula = %d \n", temp.matricula);
		printf("Nome = %s \n", temp.nome);
	}
	else
		printf("\nItem nao recuperado 1\n");
	
	// Deletar aluno
	if (removeHash_SemColisao(hash_main, 307381) == 1)
		printf("\nItem removido com sucesso 1\n");
	else
		printf("\nItem nao encontrado 1\n");
	
	// Excluir Hash
	liberaHash(hash_main);
	
	return 0;
}
