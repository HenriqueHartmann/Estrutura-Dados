#include <stdio.h>

/*
 	Digita o numero de posições em n,
 	então digitamos as posições de largada 
 	e chegada. Então percorremos de 0 até n
 	e mais uma vez de 0 até n para encontrarmos
 	a posição de indices da chegada e criarmos um
 	vetor. Depois percorremos de 0 até n e de i + 1
 	até n e comparamos se a posição i do vetor e
 	maior que que a posição j aplicamos a ordenacao
 	e adicionamos mais 1 na contagem de mudanças.
*/

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
