#include <stdio.h>

void percorrer (int i, int j);

int main()
{
	int i = 1, j = 60;
	percorrer(i, j);
	
	return 0;
}

void percorrer (int i, int j)
{
	if (j >= 0)
	{
		printf("I=%d J=%d\n", i, j);
		percorrer(i + 3, j - 5);
	}
}

