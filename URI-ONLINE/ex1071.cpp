#include <stdio.h>

void odd (int min, int max, int *ps);
int soma (int x, int y);

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n", soma(x, y));
	
	return 0;
}

void odd (int min, int max, int *ps)
{
	if (min < max)
	{
		if (min % 2 != 0)
		{
			*ps += min;
		}
		odd(min + 1, max, ps);	
	}
}

int soma (int x, int y)
{
	int soma = 0;
	
	if (x > y)
	{
		odd(y + 1, x, &soma);
		return soma;
	}
	else if (y > x)
	{
		odd(x + 1, y, &soma);
		return soma;
	}
	else
	{
		return 0;
	}
}

