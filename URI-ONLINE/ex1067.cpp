#include <stdio.h>

void odd (int v, int x);

int main()
{
	int x;
	scanf("%d", &x);
	odd(1, x);
	
	return 0;
}

void odd (int v, int x)
{
	if (v <= x)
	{
		if (v % 2 != 0)
		{
			printf("%d\n", v);	
		}
		odd(v + 1, x);	
	}
}

