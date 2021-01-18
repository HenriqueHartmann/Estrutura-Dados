#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

void operacoes(int *pa, int *pb, int *psum, int *psub)
{
	int soma, subtracao;
	
	*psum = *pa + *pb;
	*psub = *pa - *pb;
	
}

int main (void)
{
	int a = 5;
	int b = 5;
	int soma, subtracao;
	
	operacoes(&a, &b, &soma, &subtracao);
	
	printf("Soma: %d + %d = %d\n", a, b, soma);
	printf("Subtracao: %d - %d = %d\n", a, b, subtracao);
	
	return 0;	
}

