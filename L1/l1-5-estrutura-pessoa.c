#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

typedef struct pessoa {
	char nome[51];
	int idade;
	char endereco[51];
} Pessoa;

int main (void)
{
	Pessoa p;
	
	printf("Digite o seu nome (MAX: 51): ");
	gets(p.nome);
	
	printf("Digite a sua idade: ");
	scanf("%d", &p.idade);
	
	fflush(stdin);
	
	printf("Digite o seu endereco (MAX: 51):");
	gets(p.endereco);
	
	printf("nome: %s\nidade: %d\nendereco: %s\n", p.nome, p.idade, p.endereco);
	
	return 0;
}

