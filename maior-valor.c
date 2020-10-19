#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

float maior_valor(float a, float b, float c)
{
	float m = a;
	
	if (b > m)
	{
		m = b;
	}
	if (c > m)
	{
		m = c;
	}
	
	return m;
}

int main(void) 
{
	float a,b,c,m;
	
	printf("Digite 3 valores \n");
	
	printf("Primeiro valor: ");
	scanf("%f", &a);
	fflush(stdin);
	
	printf("Segundo valor: ");
	scanf("%f", &b);
	fflush(stdin);
	
	printf("Terceiro valor: ");
	scanf("%f", &c);
	
	m = maior_valor(a, b, c);
	
	printf("O maior valor e: %f\n", m);
	
	return 0;
}
