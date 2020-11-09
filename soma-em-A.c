#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* Função soma */
void soma (int *pa, int *pb)
{
	/* Soma a e b e atribui o resultado em a */
	*pa += *pb;
}

int main (void)
{
	/* Declarar e inicializar variaveis a e b */
	int a = 5, b = 3;
	
	/* Chama função soma e passa os endereços de a e b como parâmetro */ 
	soma(&a, &b);
	
	/* Imprime os valores de a e b na tela */
	printf("A = %d | B = %d", a, b);
	
	/* Fim do programa */
	return 0;
}
