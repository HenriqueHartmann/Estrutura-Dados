#include <stdio.h>

void pares (int n);

int main()
{
	int n = 2;
	pares(2);
		
	return 0;
}

void pares (int n)
{
	if (n <= 100)
	{
		printf("%d\n", n);
		pares(n + 2);
	}
}

