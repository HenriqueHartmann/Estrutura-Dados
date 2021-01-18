#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

int main (void)
{
	int qtd = 20;
	float v[qtd];
	int i;
	
	for (i = 0; i < qtd; i++)
	{
		v[i] = i + 1;
	}
	
	for (i = (qtd - 1); i >= 0; i--)
	{
		printf("%f \n", v[i]);
	}
	
	return 0;
}

