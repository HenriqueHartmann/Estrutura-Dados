#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

// Prot�tipo das fun��es
int soma (int a, int b); // Fun��o para calcular a soma entre dois n�meros inteiros
int sub (int a, int b); // Fun��o para calcular a subtra��o entre dois n�meros inteiros 
int mult (int a, int b); // Fun��o para calcular a multiplica��o entre dois n�meros inteiros
float div (int a, int b); // Fun��o para calcular a divis�o entre dois n�meros inteiros

// Fun��o Main
int main (void)
{
	// Declara��o das variaveis a e b do tipo inteiro
	int a = 3; // a armazena o valor recebido
	int b = 6; // b armazena o valor recebido
	
	// Declarando e atribuindo os valores das variaveis com o resultado das fun��es
	int vsoma = soma(a, b); // Recebe o valor do retorno da fun��o soma
	int vsub = sub(a, b); // Recebe o valor do retorno da fun��o sub
	int vmult = mult(a, b); // Recebe o valor do retorno da fun��o mult
	float vdiv = div(a, b); // Recebe o valor do retorno da fun��o div
	
	// Imprimindo o resultado das quatro opera��es b�sicas entre os dois n�meros inteiros
	printf("Soma: %d | Subtracao: %d | Multiplicacao: %d | Divisao: %f", vsoma, vsub, vmult, vdiv);
	
	// Fim do programa
	return 0;
}

// Desenvolvimento das Fun��es
int soma (int a, int b)
{
	return a + b; // Retorna o resultado da soma de a + b
}

int sub (int a, int b)
{
	return a - b; // Retorna o resultado da subtra��o de a - b
}

int mult (int a, int b)
{
	return a * b; // Retorna o resultado da multiplica��o de a x b
}

float div (int a, int b)
{
	// Converte os valores inteiros para float para o resultado ser diferente de 0, em caso do primeiro valor ser menor que o segundo
	float r = ((float)a / b);
	return r; // Retorna o resultado da divis�o de a / b
}

