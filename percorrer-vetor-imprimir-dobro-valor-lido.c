#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

int main (void)
{
	/* Declara vetor com 5 elementos */
	int v[5];
	
	/* Variável usada como índice do vetor */
	int i;
	
	/* Leitura dos valores */
	for (i = 0; i < 5; i++) /* Faz índice variar de 0 a 4 */
	{
		/* Imprime enunciado */
		printf("Digite o %d numero \n", i+1);
		
		/* Captura valor de entrada via teclado e atribui a posição do vetor */
		scanf("%d", &v[i]); /* Lê cada elemento do vetor*/
	}
	
	/* Ler vetor e dobrar valores lidos e imprimir na tela */
	for (i = 0; i < 5; i++)
	{
		printf("%d = %d \n", i+1, v[i]*2);
	}
	
	/* Fim do programa */
	return 0;
}
