#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

int main(void)
{
	/* Declarar e inicializar variaveis. Declarar ponteiros */
	int v1 = 1, *p1;
	float v2 = 2, *p2;
	char v3 = '3', *p3;
	
	/* Imprimi os valores das variveis */
	printf("Antigo: \nValor1 = %d // Valor2 = %f // Valor3 = %c \n", v1, v2, v3);
	
	/* Inicializa e atribui aos ponteiros o endereço das variaveis correspondentes */
	p1 = &v1;
	p2 = &v2;
	p3 = &v3;
	
	/* Altera o valor das variaveis por meio dos ponteiros */
	*p1 = 2;
	*p2 = 3;
	*p3 = '4';
	
	/* Imprimi os valores das variveis */
	printf("Novo: \nValor1 = %d // Valor2 = %f // Valor3 = %c", v1, v2, v3);
	
	/* Fim do programa */
	return 0;
}
