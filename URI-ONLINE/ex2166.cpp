#include <stdio.h>

double root (int n);

int main()
{
	int n;
	
	scanf("%d", &n);
	
	double rst = root(n);
	
	printf("%.10lf\n", rst + 1);
	
	return 0;
}

double root (int n)
{
	if (n == 0)
		return 0;

	return 1 / (2 + root(n - 1));
}

