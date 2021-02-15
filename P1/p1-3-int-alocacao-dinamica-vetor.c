#include <stdio.h>
#include <stdlib.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

// Prot�tipo das fun��es
int entrada (); // Captura um valor inteiro digitado pelo usu�rio e retorna esse valor
void imprimir (int *v, int n); // Imprimi o conte�do de um vetor

int main (void)
{
	int *v; // Declara��o do vetor
	int n = 0; // Declara e atribui a variavel inteira n igual a 0
	int i = 0; // Declara e atribui a variavel inteira i igual a 0
	
	do // Ele executa uma vez e ai verifica se a condi��o � verdadeira, se sim ele continua at� a condi��o se tornar falsa
	{
		n = entrada(); // Atribui o valor de n para o retorna da fun��o entrada
	}
	while (n < 1); // Enquanto n for menor que 1, ele executa o c�digo dentro de do
	
	v = (int*) malloc(n*sizeof(int)); // Aloca��o din�mica do vetor, seu tamanho � definido pelo valor da variavel n
	if (v == NULL) // Verifica se o vetor � igual a NULL, caso a condi��o for verdadeira ele imprime a mensagem e retorna 1 encerrando o programa
	{
		printf("Mem�ria Insuficiente. \n"); // Imprime a mensagem
		return 1; // Retorna o valor 1
	}
	
	printf("\n Por favor agora insira o conte�do do vetor: \n"); // Imprime a mensagem
	
	while (i < n) // Realiza o c�digo enquanto i for menor que n
	{
		v[i] = entrada(); // Atribui o valor do vetor na posi��o i igual ao retorno da fun��o entrada
		i++; // Incrementa + 1 em i
	}
	
	imprimir(v, n); // Chama a fun��o imprimir
	
	free(v); // Libera mem�ria
	
	// Fim do programa	
	return 0;
}

// Desenvolvimento das fun��es
int entrada ()
{
	int n = 0; // Declara e atribui a variavel inteira n igual a 0
	printf("Digite um valor inteiro maior que zero: "); // Imprime a mensagem
	scanf("%d", &n); // Captura o valor de entrada via teclado e atribui a variavel n
	return n; // Retorna o valor de n
}

void imprimir (int *v, int n)
{
	int i = 0; // Declara e atribui a variavel inteira i igual a 0
	for (i; i < n; i++) // Le o vetor, por meio da variavel i, verificando a cada incremento se continua sendo menor que n
	{
		printf("%d \n", v[i]); // Imprimir a mensagem com valor do vetor na posi��o i
	}
}

