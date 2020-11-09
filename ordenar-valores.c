#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* Função ordenar */
int ordenar (int *px, int *py, int *pz)
{
	/* Declarar variável temp */
	int temp;
	
	/* Verifica se z é menor que y */
	if (*pz < *py)
	{
		/* Em caso verdadeiro, trocam-se os valores entre y e z */
		temp = *pz;
		*pz = *py;
		*py = temp;
	}
		
	/* Verifica se x é maior que y */
	if (*px > *py)
	{
		/* Em caso verdadeiro, trocam-se os valores entre x e y */
		temp = *py;
		*py = *px;
		*px = temp;
	}
	
	/* Verifica se y é maior que z */
	if (*py > *pz)
	{
		/* Em caso verdadeiro, trocam-se os valores entre y e z */
		temp = *pz;
		*pz = *py;
		*py = temp;
	}
	
	/* Verifica se x == y == z */
	if (*px == *py && *px == *pz)
	{
		/* Em caso verdadeiro retorna 1 */
		return 1;
	} 
	else 
	{
		/* Em caso falso retorna 0 */
		return 0;
	}
}

int main (void)
{
	/* Declarar e inicializar variaveis x, y e z */
	int x = 2, y = 2, z = 2;
	
	/* Chamar função ordenar e imprimir seu resultado */
	printf("%d \n", ordenar(&x, &y, &z));
	
	/* Imprimir valores de x, y e z */
	printf("x = %d, y = %d, z = %d \n", x, y, z);
	
	/* Fim do programa */
	return 0;
}
