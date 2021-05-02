#include <stdio.h>

int fib (int n, int *pc);

int main()
{
	int n, i, x, rst;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		int count = 0;
		scanf("%d", &x);
		rst = fib(x, &count);
		printf("fib(%d) = %d calls = %d\n", x, count - 1, rst);
	}
	
	return 0;
}

int fib (int n, int *pc)
{
	*pc += 1;
	
	if (n < 2)
		return n;
		
	return fib(n-1, pc) + fib(n-2, pc);
}

