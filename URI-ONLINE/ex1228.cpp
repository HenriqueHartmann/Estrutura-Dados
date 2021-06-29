#include <stdio.h>

int main()
{
	int largada[24], chegada[24];
	int n, i, j;
	
	while(scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &largada[i]);
		
		for (i = 0; i < n; i++)
			scanf("%d", &chegada[i]);
		
		int vetor[n], count = 0, aux;
		
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (largada[i] == chegada[j])
	            {
	                vetor[j] = i;
	            }
		
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (vetor[i] > vetor[j])
				{
					aux = vetor[j];
					vetor[j] = vetor[i];
					vetor[i] = aux;
					count++;
				}
		
		printf("%d\n", count);
	}
	
	return 0;
}

