#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

// Protótipo das funções
int soma (int a, int b); // Função para calcular a soma entre dois números inteiros
int sub (int a, int b); // Função para calcular a subtração entre dois números inteiros 
int mult (int a, int b); // Função para calcular a multiplicação entre dois números inteiros
float div (int a, int b); // Função para calcular a divisão entre dois números inteiros

// Função Main
int main (void)
{
	// Declaração das variaveis a e b do tipo inteiro
	int a = 3; // a armazena o valor recebido
	int b = 6; // b armazena o valor recebido
	
	// Declarando e atribuindo os valores das variaveis com o resultado das funções
	int vsoma = soma(a, b); // Recebe o valor do retorno da função soma
	int vsub = sub(a, b); // Recebe o valor do retorno da função sub
	int vmult = mult(a, b); // Recebe o valor do retorno da função mult
	float vdiv = div(a, b); // Recebe o valor do retorno da função div
	
	// Imprimindo o resultado das quatro operações básicas entre os dois números inteiros
	printf("Soma: %d | Subtracao: %d | Multiplicacao: %d | Divisao: %f", vsoma, vsub, vmult, vdiv);
	
	// Fim do programa
	return 0;
}

// Desenvolvimento das Funções
int soma (int a, int b)
{
	return a + b; // Retorna o resultado da soma de a + b
}

int sub (int a, int b)
{
	return a - b; // Retorna o resultado da subtração de a - b
}

int mult (int a, int b)
{
	return a * b; // Retorna o resultado da multiplicação de a x b
}

float div (int a, int b)
{
	// Converte os valores inteiros para float para o resultado ser diferente de 0, em caso do primeiro valor ser menor que o segundo
	float r = ((float)a / b);
	return r; // Retorna o resultado da divisão de a / b
}

