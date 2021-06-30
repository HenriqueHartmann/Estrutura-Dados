#include <stdio.h>

void fatorial(int n, int *pv);

int main()
{
	int n, v = 1;
	scanf("%d", &n);
	
	if (n < 0 || n > 13)
		return 1;
	
	fatorial(n, &v);
	printf("%d\n", v);
	
	return 0;
}

void fatorial(int n, int *pv)
{
	if (n > 0)
	{
		*pv = *pv * n;
		fatorial(n - 1, pv);	
	}
}
  
