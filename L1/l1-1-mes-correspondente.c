#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

int main (void)
{
	int num;
	printf("Digite um numero inteiro entre 1 e 12: ");
	scanf("%d", &num);
	if (num < 1 || num > 12)
	{
		printf("Digite um valor valido\n");
		return 1;
	}
	
	char meses[12][10] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
	puts(meses[(num -1)]);
	
	return 0;
}

