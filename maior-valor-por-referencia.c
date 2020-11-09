#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* Fun��o troca */
void troca (int *px, int *py)
{
	/* Verifica se o valor de y � maior que o de x*/
	if (*py > *px)
	{
		/* Caso verdadeiro atribui o maior valor a x e o menor a y, por meio dos ponteiros*/
		int temp = *px;
		*px = *py;
		*py = temp;
	}
}

int main(void)
{
	/* Declarar e inicializar variaveis x e y */
	int x = 1, y = 3;
	
	/* Chama a fun��o troca e passa os endere�os das variveis como par�metro*/
	troca(&x, &y);
	
	/* Imprime os valores de x e y na tela */
	printf("X = %d | Y = %d \n", x, y);
	
	/* Fim do programa */
	return 0;
}
