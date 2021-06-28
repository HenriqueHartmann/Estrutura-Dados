#include <stdio.h>

/*
	Imprime a multiplicação de i * n, 
	com i iniciando sendo 1 e terminando
	em 10 usando recursão.
*/
void multiply(int n, int i);

int main()
{
	int n, i = 1;
	scanf("%d", &n);
	
	multiply(n, i);
	
	return 0;
}


void multiply(int n, int i)
{
	printf("%d x %d = %d\n", i, n, i*n);
	i++;
	if (i < 11)
	{
		multiply(n, i);
	}
}

