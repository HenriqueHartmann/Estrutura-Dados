#include <stdio.h>
#include <stdlib.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* Calcula o tamanho de uma string */
void tamanho(char *str, int *strsize)
{
	int i = 0;
	char final = str[i];
	
	while (final != 0)
	{
		final = str[i];
		i++;
	}
	
	*strsize = i-1;
}

int main(void)
{
	/* Declaração de variáveis */
	char str[] = "tee";
	int* strsize = (int*) malloc(sizeof(int)); //Alocação de dinâmica
	if (strsize == NULL) // Verifica se foi feito a alocação
	{
		printf("Memoria Insuficiente");
	}
	
	tamanho(str, strsize);
	printf("Tamanho de %s = %d", str, *strsize);
	
	/* Libera memória */
	free(strsize);
	
	/* Fim do programa */
	return 0;
}
