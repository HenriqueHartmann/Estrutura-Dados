#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* Fun��o soma */
void soma (int *pa, int *pb)
{
	/* Soma a e b e atribui o resultado em a */
	*pa += *pb;
}

int main (void)
{
	/* Declarar e inicializar variaveis a e b */
	int a = 5, b = 3;
	
	/* Chama fun��o soma e passa os endere�os de a e b como par�metro */ 
	soma(&a, &b);
	
	/* Imprime os valores de a e b na tela */
	printf("A = %d | B = %d", a, b);
	
	/* Fim do programa */
	return 0;
}
