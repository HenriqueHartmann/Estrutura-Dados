#include <stdio.h>

void pares (int n, int c);

int main()
{
	int c, n = 2;
	scanf("%d", &c);
	pares(n, c);
	
	return 0;
}

void pares (int n, int c)
{
	if (n <= c)
	{
		printf("%d^2 = %d\n", n, n*n);
		pares(n + 2, c);
	}
}

